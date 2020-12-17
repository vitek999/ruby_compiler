#pragma once

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
};