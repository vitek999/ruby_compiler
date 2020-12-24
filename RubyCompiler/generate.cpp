#include "generate.h"

using namespace std;

void generate(program_struct* program, const std::map<std::string, Clazz*>& clazzList) {

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
		vector<char> len = intToBytes(constant.utf8_id);	
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