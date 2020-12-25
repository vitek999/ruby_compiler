#include "generate.h"

void generate(program_struct* program, const std::map<std::string, Clazz*>& clazzList) {
	for (auto clazz : clazzesList) {
		freopen("__PROGRAM__.class", "wb", stdout);
		std::vector<char> len = intToBytes(clazz.second->constants.size() + 1);
		// CAFEBABE
		std::cout << (char)0xCA << (char)0xFE << (char)0xBA << (char)0xBE;
		// JAVA 8 (version 52.0 (0x34))
		std::cout << (char)0x00 << (char)0x00 << (char)0x00 << (char)0x34;
		// constants count
		std::cout << len[2] << len[3];

		//constants table
		std::vector<std::pair<Constant, int>> constants_v;

		for (auto& it : clazz.second->constants) {
			constants_v.push_back(it);
		}
		
		sort(constants_v.begin(), constants_v.end(), cmp);

		for (auto i : constants_v) {
			generate(i.first);
		}

		// Flags 
		std::cout << (char)0x00 << (char)0x21;
		// This class constant
		std::vector<char> bytes = intToBytes(clazz.second->number);
		std::cout << bytes[2] << bytes[3];
		// Parent class constant
		bytes = intToBytes(clazz.second->parend_number);
		std::cout << bytes[2] << bytes[3];
		// Interfaces table
		std::cout << (char)0x00 << (char)0x00;
		std::cout << (char)0x00 << (char)0x00;
		// methods count
		bytes = intToBytes(clazz.second->methods.size());
		std::cout << bytes[2] << bytes[3];
		
		// !!!!!!!!! METHODS !!!!!!
		
		// public 
		std::cout << (char)0x00 << (char)0x01;
		// init name
		bytes = intToBytes(clazz.second->methods["<init>"]->nameNumber);
		std::cout << bytes[2] << bytes[3];
		// init descriptor ()V
		bytes = intToBytes(clazz.second->methods["<init>"]->descriptorNumber);
		std::cout << bytes[2] << bytes[3];
		// method atributes count (01)
		std::cout << (char)0x00 << (char)0x01;
		// method atribute (Code - 0x01)
		std::cout << (char)0x00 << (char)0x01;

		// method code
		std::vector<char> method_code_bytes = generateConstructor(clazz.second->methods["<init>"]);
		// size of code
		bytes = intToBytes(method_code_bytes.size());
		for (auto i : bytes) {
			std::cout << i;
		}

		for (auto i : method_code_bytes) {
			std::cout << i;
		}

		for (auto i : clazz.second->methods) {
			if (i.first != "<init>") {
				generate(i.second);
			}
		}

		// atributes
		std::cout << (char)0x00 << (char)0x00;
	}
}

void generate(Method* method) {
	std::vector<char> bytes;
	// public 
	if (method->isStatic) {
		std::cout << (char)0x00 << (char)0x09;
	}
	else {
		std::cout << (char)0x00 << (char)0x01;
	}
	// init name
	bytes = intToBytes(method->nameNumber);
	std::cout << bytes[2] << bytes[3];
	// init descriptor ()V
	bytes = intToBytes(method->descriptorNumber);
	std::cout << bytes[2] << bytes[3];
	
	// method atributes count (01)
	std::cout << (char)0x00 << (char)0x01;
	// method atribute (Code - 0x01)
	std::cout << (char)0x00 << (char)0x01;

	std::vector<char> result_bytes = std::vector<char>();

	// size of operands stack
	std::vector<char> tmp_bytes = intToBytes(1000);
	result_bytes.push_back(tmp_bytes[2]);
	result_bytes.push_back(tmp_bytes[3]);

	// size of local variables
	tmp_bytes = intToBytes(method->local_variables.size());
	result_bytes.push_back(tmp_bytes[2]);
	result_bytes.push_back(tmp_bytes[3]);

	std::vector<char> code_bytes = std::vector<char>();

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
		std::cout << i;
	}

	for (auto i : result_bytes) {
		std::cout << i;
	}
}

std::vector<char> generateConstructor(Method* m) {
	std::vector<char> result_bytes = std::vector<char>();

	// size of operands stack
	std::vector<char> tmp_bytes = intToBytes(1000);
	result_bytes.push_back(tmp_bytes[2]);
	result_bytes.push_back(tmp_bytes[3]);

	// size of local variables
	tmp_bytes = intToBytes(m->local_variables.size());
	result_bytes.push_back(tmp_bytes[2]);
	result_bytes.push_back(tmp_bytes[3]);

	std::vector<char> code_bytes = std::vector<char>();
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
		std::cout << (char)Constant::Type::Utf8;
		std::vector<char> len = intToBytes(strlen(c));
		std::cout << (char)len[2] << (char)len[3];
		for (int i = 0; i < strlen(c); ++i) {
			std::cout << c[i];
		}
	}

	// Integer
	if (constant.type == Constant::Type::Integer) {
		std::cout << (char)Constant::Type::Integer;
		std::vector<char> len = intToBytes(constant.iVal);
		std::cout << len[0] << len[1] << len[2] << len[3];
	}

	// Float
	if (constant.type == Constant::Type::Float) {
		std::cout << (char)Constant::Type::Float;
		std::vector<char> len = flToBytes(constant.fVal);
		std::cout << len[0] << len[1] << len[2] << len[3];
	}

	// Class
	if (constant.type == Constant::Type::Class) {
		std::cout << (char)Constant::Type::Class;
		std::vector<char> len = intToBytes(constant.class_name_id);
		std::cout << len[2] << len[3];
	}

	// String
	if (constant.type == Constant::Type::String) {
		std::cout << (char)Constant::Type::String;
		std::vector<char> len = intToBytes(constant.utf8_id);
		std::cout << len[2] << len[3];
	}

	// Fieldref
	if (constant.type == Constant::Type::Fieldref) {
		std::cout << (char)Constant::Type::Fieldref;
		std::vector<char> len = intToBytes(constant.class_id);
		std::cout << len[2] << len[3];
		len = intToBytes(constant.name_and_type_id);
		std::cout << len[2] << len[3];
	}

	// Methodref
	if (constant.type == Constant::Type::Methodref) {
		std::cout << (char)Constant::Type::Methodref;
		std::vector<char> len = intToBytes(constant.class_id);
		std::cout << len[2] << len[3];
		len = intToBytes(constant.name_and_type_id);
		std::cout << len[2] << len[3];
	}

	// NameAndType
	if (constant.type == Constant::Type::NameAndType) {
		std::cout << (char)Constant::Type::NameAndType;
		std::vector<char> len = intToBytes(constant.name_id);
		std::cout << len[2] << len[3];
		len = intToBytes(constant.type_id);
		std::cout << len[2] << len[3];
	}
}

std::vector<char> generate(expr_struct* expr) {
	std::vector<char> resultCode = std::vector<char>();
	std::vector<char> tmp = std::vector<char>();
	expr_struct* c = 0;
	int counter = 0;

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
	case var_or_method:
		resultCode.push_back((char)Command::aload);
		resultCode.push_back(intToBytes(expr->local_var_num)[3]);
		break;
	case plus:
	case minus:
	case mul:
	case div_:
	case mod:
	case equal:
	case not_equal:
	case less:
	case greater:
	case greater_eql:
	case less_eql:
	case pow_:
	case logical_and:
	case logical_or:
	case member_access:
		tmp = generate(expr->left);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		tmp = generate(expr->right);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		resultCode.push_back((char)Command::invokevirtual);
		tmp = intToBytes(expr->id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case method_call:
		// TODO: Improve! (Now works only with static methods)
		if (expr->list != 0) {
			c = expr->list->first;
			while (c != 0) {
				tmp = generate(c);
				resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
				c = c->next;
			}
		}
		resultCode.push_back((char)Command::invokestatic);
		tmp = intToBytes(expr->id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	case array:
		resultCode.push_back((char)Command::new_);
		tmp = intToBytes(expr->class_id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::dup);
		resultCode.push_back((char)Command::new_);
		tmp = intToBytes(expr->array_list_class_id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::dup);
		tmp = intToBytes(count_exprs(expr->list));
		resultCode.push_back((char)Command::sipush);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::anewarray);
		tmp = intToBytes(expr->class_id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::dup);

		// Add elements
		c = expr->list->first;
		while (c != 0) {
			tmp = intToBytes(counter);
			resultCode.push_back((char)Command::sipush);
			resultCode.push_back(tmp[2]);
			resultCode.push_back(tmp[3]);
			tmp = generate(c);
			resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
			resultCode.push_back((char)Command::aastore);
			resultCode.push_back((char)Command::dup);
			++counter;
			c = c->next;
		}
		// because after last element we dup data.
		resultCode.push_back((char)Command::pop);
		// call Arrays.asList
		resultCode.push_back((char)Command::invokestatic);
		tmp = intToBytes(expr->list_constructor_mr);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		
		// create ArrayList
		resultCode.push_back((char)Command::invokespecial);
		tmp = intToBytes(expr->array_list_constructor_mr);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		resultCode.push_back((char)Command::invokespecial);
		tmp = intToBytes(expr->id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		//resultCode.push_back((char)Command::pop);
		break;
	case member_access_and_assign: 
		tmp = generate(expr->left);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		tmp = generate(expr->index);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		tmp = generate(expr->right);
		resultCode.insert(resultCode.end(), tmp.begin(), tmp.end());
		resultCode.push_back((char)Command::invokevirtual);
		tmp = intToBytes(expr->id);
		resultCode.push_back(tmp[2]);
		resultCode.push_back(tmp[3]);
		break;
	default:
		break;
	}

	return resultCode;
}

std::vector<char> generate(stmt_list_struct* list) {
	std::vector<char> resultCode = std::vector<char>();
	std::vector<char> tmp = std::vector<char>();

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