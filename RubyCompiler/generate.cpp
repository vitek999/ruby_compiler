#include "generate.h"

using namespace std;

void generate(program_struct* program, const std::map<std::string, Clazz*>& clazzList) {
	for (auto clazz : clazzesList) {
		freopen("generated.class", "wb", stdout);
		vector<char> len = intToBytes(clazz.second->constants.size() + 1);
		// CAFEBABE
		cout << (char)0xCA << (char)0xFE << (char)0xBA << (char)0xBE;
		// JAVA 8 (version 52.0 (0x34))
		cout << (char)0x00 << (char)0x00 << (char)0x00 << (char)0x34;
		// constants count
		cout << len[2] << len[3];

		//constants table
		vector<pair<Constant, int>> constants_v;

		for (auto& it : clazz.second->constants) {
			constants_v.push_back(it);
		}
		
		sort(constants_v.begin(), constants_v.end(), cmp);

		for (auto i : constants_v) {
			generate(i.first);
		}

		// Flags 
		cout << (char)0x00 << (char)0x21;
		// This class constant
		vector<char> bytes = intToBytes(clazz.second->number);
		cout << bytes[2] << bytes[3];
		// Parent class constant
		bytes = intToBytes(clazz.second->parend_number);
		cout << bytes[2] << bytes[3];
		// Interfaces table
		cout << (char)0x00 << (char)0x00;
		cout << (char)0x00 << (char)0x00;
		// methods count
		bytes = intToBytes(clazz.second->methods.size());
		cout << bytes[2] << bytes[3];
		
		// !!!!!!!!! METHODS !!!!!!
		
		// public 
		cout << (char)0x00 << (char)0x01;
		// init name
		bytes = intToBytes(clazz.second->methods["<init>"]->nameNumber);
		cout << bytes[2] << bytes[3];
		// init descriptor ()V
		bytes = intToBytes(clazz.second->methods["<init>"]->descriptorNumber);
		cout << bytes[2] << bytes[3];
		// method atributes count (01)
		cout << (char)0x00 << (char)0x01;
		// method atribute (Code - 0x01)
		cout << (char)0x00 << (char)0x01;

		// method code
		vector<char> method_code_bytes = generateConstructor(clazz.second->methods["<init>"]);
		// size of code
		bytes = intToBytes(method_code_bytes.size());
		for (auto i : bytes) {
			cout << i;
		}

		for (auto i : method_code_bytes) {
			cout << i;
		}

		for (auto i : clazz.second->methods) {
			if (i.first != "<init>") {
				generate(i.second);
			}
		}

		// atributes
		cout << (char)0x00 << (char)0x00;
	}
}

void generate(Method* method) {
	vector<char> bytes;
	// public 
	if (method->isStatic) {
		cout << (char)0x00 << (char)0x09;
	}
	else {
		cout << (char)0x00 << (char)0x01;
	}
	// init name
	bytes = intToBytes(method->nameNumber);
	cout << bytes[2] << bytes[3];
	// init descriptor ()V
	bytes = intToBytes(method->descriptorNumber);
	cout << bytes[2] << bytes[3];
	
	// method atributes count (01)
	cout << (char)0x00 << (char)0x01;
	// method atribute (Code - 0x01)
	cout << (char)0x00 << (char)0x01;

	vector<char> result_bytes = vector<char>();

	// size of operands stack
	vector<char> tmp_bytes = intToBytes(1000);
	result_bytes.push_back(tmp_bytes[2]);
	result_bytes.push_back(tmp_bytes[3]);

	// size of local variables
	tmp_bytes = intToBytes(method->local_variables.size());
	result_bytes.push_back(tmp_bytes[2]);
	result_bytes.push_back(tmp_bytes[3]);

	vector<char> code_bytes = vector<char>();

	// generate code.

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TODO!!!!!!!!
	if (method != 0 && method->body != 0) {
		tmp_bytes = generate(method->body);
		code_bytes.insert(code_bytes.end(), tmp_bytes.begin(), tmp_bytes.end());
	}

	code_bytes.push_back((char)Command::return_);

	// size of code
	tmp_bytes = intToBytes(code_bytes.size());
	for (auto i : tmp_bytes) {
		result_bytes.push_back(i);
	}

	// code from code_bytes
	for (auto i : code_bytes) {
		result_bytes.push_back(i);
	}

	// exception table 
	result_bytes.push_back((char)0x00);
	result_bytes.push_back((char)0x00);

	// attrs table
	result_bytes.push_back((char)0x00);
	result_bytes.push_back((char)0x00);

	bytes = intToBytes(result_bytes.size());
	for (auto i : bytes) {
		cout << i;
	}

	for (auto i : result_bytes) {
		cout << i;
	}
}

std::vector<char> generateConstructor(Method* m) {
	vector<char> result_bytes = vector<char>();

	// size of operands stack
	vector<char> tmp_bytes = intToBytes(1000);
	result_bytes.push_back(tmp_bytes[2]);
	result_bytes.push_back(tmp_bytes[3]);

	// size of local variables
	tmp_bytes = intToBytes(m->local_variables.size());
	result_bytes.push_back(tmp_bytes[2]);
	result_bytes.push_back(tmp_bytes[3]);

	vector<char> code_bytes = vector<char>();
	code_bytes.push_back((char)0x2A);  // aload_0
	code_bytes.push_back((char)Command::invokespecial); // invoke special 
	
	// java/lang/Object.<init>()V					
	tmp_bytes = intToBytes(m->self_method_ref);
	code_bytes.push_back(tmp_bytes[2]);
	code_bytes.push_back(tmp_bytes[3]);
	
	code_bytes.push_back((char)Command::return_); 	// return
	
	// size of code
	tmp_bytes = intToBytes(code_bytes.size());
	for (auto i : tmp_bytes) {
		result_bytes.push_back(i);
	}

	// code from code_bytes
	for (auto i : code_bytes) {
		result_bytes.push_back(i);
	}

	// exception table 
	result_bytes.push_back((char)0x00);
	result_bytes.push_back((char)0x00);

	// attrs table
	result_bytes.push_back((char)0x00);
	result_bytes.push_back((char)0x00);

	return result_bytes;
}

void generate(Constant constant) {
	// UTF-8
	if (constant.type == Constant::Type::Utf8) {
		char const* c = constant.sVal.c_str();
		cout << (char)Constant::Type::Utf8;
		vector<char> len = intToBytes(strlen(c));
		cout << (char)len[2] << (char)len[3];
		for (int i = 0; i < strlen(c); ++i) {
			cout << c[i];
		}
	}

	// Integer
	if (constant.type == Constant::Type::Integer) {
		cout << (char)Constant::Type::Integer;
		vector<char> len = intToBytes(constant.iVal);
		cout << len[0] << len[1] << len[2] << len[3];
	}

	// Float
	if (constant.type == Constant::Type::Float) {
		cout << (char)Constant::Type::Float;
		vector<char> len = flToBytes(constant.fVal);
		cout << len[0] << len[1] << len[2] << len[3];
	}

	// Class
	if (constant.type == Constant::Type::Class) {
		cout << (char)Constant::Type::Class;
		vector<char> len = intToBytes(constant.class_name_id);	
		cout << len[2] << len[3];
	}

	// String
	if (constant.type == Constant::Type::String) {
		cout << (char)Constant::Type::String;
		vector<char> len = intToBytes(constant.utf8_id);
		cout << len[2] << len[3];
	}

	// Fieldref
	if (constant.type == Constant::Type::Fieldref) {
		cout << (char)Constant::Type::Fieldref;
		vector<char> len = intToBytes(constant.class_id);
		cout << len[2] << len[3];
		len = intToBytes(constant.name_and_type_id);
		cout << len[2] << len[3];
	}

	// Methodref
	if (constant.type == Constant::Type::Methodref) {
		cout << (char)Constant::Type::Methodref;
		vector<char> len = intToBytes(constant.class_id);
		cout << len[2] << len[3];
		len = intToBytes(constant.name_and_type_id);
		cout << len[2] << len[3];
	}

	// NameAndType
	if (constant.type == Constant::Type::NameAndType) {
		cout << (char)Constant::Type::NameAndType;
		vector<char> len = intToBytes(constant.name_id);
		cout << len[2] << len[3];
		len = intToBytes(constant.type_id);
		cout << len[2] << len[3];
	}
}

std::vector<char> generate(expr_struct* expr) {
	vector<char> resultCode = vector<char>();
	vector<char> tmp = vector<char>();

	switch (expr->type)
	{
	case Integer:
		resultCode.push_back((char)Command::new_);
		tmp = intToBytes(expr->class_id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::dup);
		tmp = intToBytes(expr->int_val);
		resultCode.push_back((char)Command::sipush);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::invokespecial);
		tmp = intToBytes(expr->id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case String: 
	case Float:
		resultCode.push_back((char)Command::new_);
		tmp = intToBytes(expr->class_id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::dup);
		resultCode.push_back((char)Command::ldc_w);
		tmp = intToBytes(expr->value_id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::invokespecial);
		tmp = intToBytes(expr->id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case Boolean:
		resultCode.push_back((char)Command::new_);
		tmp = intToBytes(expr->class_id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::dup);
		if (expr->int_val == 1) {
			resultCode.push_back((char)Command::iconst_1);
		} else {
			resultCode.push_back((char)Command::iconst_0);
		}
		resultCode.push_back((char)Command::invokespecial);
		tmp = intToBytes(expr->id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case assign:
		// TODO: Improve! (Now works only when left expression is localvar)
		tmp = generate(expr->right);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		resultCode.push_back((char)Command::astore);
		resultCode.push_back(intToBytes(expr->left->local_var_num)[3]);
		break;
	default:
		break;
	}

	return resultCode;
}

std::vector<char> generate(stmt_list_struct* list) {
	vector<char> resultCode = vector<char>();
	vector<char> tmp = vector<char>();

	stmt_struct* c = list->first;
	while (c != 0) {
		switch (c->type)
		{
		case expr_stmt_t:
			tmp = generate(c->expr_f);
			resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			break;
		default:
			break;
		}
		c = c->next;
	}

	return resultCode;
}

std::vector <char> intToBytes(int value) {
	std::vector<char> arrayOfByte(4);
	for (int i = 0; i < 4; ++i) {
		arrayOfByte[3 - i] = (value >> (i * 8));
	}
	return arrayOfByte;
}

std::vector<char> flToBytes(float value)
{
	std::vector<char> arrayOfByte(4);

	for (int i = 0; i < sizeof(float); ++i)
		arrayOfByte[3 - i] = ((char*)&value)[i];
	return arrayOfByte;
}

bool cmp(std::pair<Constant, int>& a, std::pair<Constant, int>& b) {
	return a.second < b.second;
}