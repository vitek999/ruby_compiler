#pragma once

#include <string>

struct Constant
{
	enum class Type {
		Utf8 = 1,
		Integer = 3,
		Float = 4,
		Class = 7,
		String = 8,
		Fieldref = 9,
		Methodref = 10,
		NameAndType = 12
	};

	Type type;
	
	int iVal;
	float fVal;
	std::string sVal;

	unsigned int utf8_id;
	unsigned int name_id;
	unsigned int type_id;
	unsigned int class_name_id;
	unsigned int name_and_type_id;
	unsigned int class_id;

	static Constant Utf8(std::string const& str) {
		Constant c;
		c.type = Type::Utf8;
		c.sVal = str;
		return c;
	}

	static Constant Integer(int val) {
		Constant c;
		c.type = Type::Integer;
		c.iVal = val;
		return c;
	}

	static Constant Float(float val) {
		Constant c;
		c.type = Type::Float;
		c.fVal = val;
		return c;
	}

	static Constant String(int utf8_id) {
		Constant c;
		c.type = Type::String;
		c.utf8_id = utf8_id;
		return c;
	}

	static Constant Class(int utf8_id) {
		Constant c;
		c.type = Type::Class;
		c.class_name_id = utf8_id;
		return c;
	}

	static Constant FieldRef(int class_id, int name_and_type_id) {
		Constant c;
		c.type = Type::Fieldref;
		c.class_id = class_id;
		c.name_and_type_id = name_and_type_id;
		return c;
	}

	static Constant MethodRef(int class_id, int name_and_type_id) {
		Constant c;
		c.type = Type::Methodref;
		c.class_id = class_id;
		c.name_and_type_id = name_and_type_id;
		return c;
	}

	static Constant NameAndType(int name_utf8_id, int descriptor_utf8_id) {
		Constant c;
		c.type = Type::NameAndType;
		c.name_id = name_utf8_id;
		c.type_id = descriptor_utf8_id;
		return c;
	}

	friend bool operator==(const Constant& l, const Constant& r) {
		if (l.type != r.type) return false;
		switch (l.type)
		{
		case Constant::Type::Utf8:
			return l.sVal == r.sVal;
		case Constant::Type::Integer:
			return l.iVal == r.iVal;
		case Constant::Type::Float:
			return l.fVal == r.fVal;
		case Constant::Type::String:
		case Constant::Type::Class:
			return l.utf8_id == r.utf8_id;
		case Constant::Type::NameAndType:
			return (l.name_id == r.name_id) && (l.type_id == r.type_id);
		case Constant::Type::Methodref:
		case Constant::Type::Fieldref:
			return (l.name_and_type_id == r.name_and_type_id) && (l.class_id == r.class_id);
		}
		return false;
	}

	friend bool operator<(const Constant l, const Constant r) {
		if (l.type < r.type) {
			return true;
		}
		else if (l .type == r.type) {
			switch (l.type) {
			case Constant::Type::Utf8:
				return l.sVal < r.sVal;
			case Constant::Type::Float:
				return l.fVal < r.fVal;
			case Constant::Type::Integer:
				return l.iVal < r.iVal;
			case Constant::Type::String:
				return l.utf8_id < r.utf8_id;
			case Constant::Type::Class:
				return l.class_name_id < r.class_name_id;
			case Constant::Type::NameAndType:
				return l.name_id < r.name_id || ((l.name_id == r.name_id) && (l.type_id < r.type_id));
			case Constant::Type::Fieldref:
			case Constant::Type::Methodref:
				return l.class_id < r.class_id || ((l.class_id == r.class_id) && (l.name_and_type_id < r.name_and_type_id));
			}

		}

		return false;
	}
};	