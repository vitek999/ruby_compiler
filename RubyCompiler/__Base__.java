public class __Base__ {
    private static final int INTEGER = 0;
    private static final int BOOLEAN = 1;
    private static final int FLOAT = 2;
    private static final int STRING = 3;
    private static final int NIL = 4;

    public int __iVal;
    public boolean __bVal;
    public float __fVal;
    public String __sVal;

    public int __type = -1;

    public __Base__() {
        __type = NIL;
    }

    public __Base__(int value) {
        this.__iVal = value;
        this.__type = INTEGER;
    }

    public __Base__(boolean value) {
        this.__bVal = value;
        this.__type = BOOLEAN;
    }

    public __Base__(float value) {
        this.__fVal = value;
        this.__type = FLOAT;
    }

    public __Base__(String value) {
        this.__sVal = value;
        this.__type = STRING;
    }

    public __Base__ __add__(__Base__ o) {
        if (this.__type == INTEGER && o.__type == INTEGER) {
            return new __Base__(this.__iVal + o.__iVal);
        }

        if (this.__type == INTEGER && o.__type == FLOAT) {
            return new __Base__(this.__iVal + o.__fVal);
        }

        if (this.__type == FLOAT && o.__type == INTEGER) {
            return new __Base__(this.__fVal + o.__iVal);
        }

        if (this.__type == FLOAT && o.__type == FLOAT) {
            return new __Base__(this.__fVal + o.__fVal);
        }

        if (this.__type == STRING && o.__type == STRING) {
            return new __Base__(this.__sVal + o.__sVal);
        }

        throw new UnsupportedOperationException("add isn't support operation for types: " + this.__type + " and: " + o.__type);
    }

    public __Base__ __sub__(__Base__ o) {
        if (this.__type == INTEGER && o.__type == INTEGER) {
            return new __Base__(this.__iVal - o.__iVal);
        }

        if (this.__type == INTEGER && o.__type == FLOAT) {
            return new __Base__(this.__iVal - o.__fVal);
        }

        if (this.__type == FLOAT && o.__type == INTEGER) {
            return new __Base__(this.__fVal - o.__iVal);
        }

        if (this.__type == FLOAT && o.__type == FLOAT) {
            return new __Base__(this.__fVal - o.__fVal);
        }

        throw new UnsupportedOperationException("sub isn't support operation for types: " + this.__type + " and: " + o.__type);
    }

    public __Base__ __mul__(__Base__ o) {
        if (this.__type == INTEGER && o.__type == INTEGER) {
            return new __Base__(this.__iVal * o.__iVal);
        }

        if (this.__type == INTEGER && o.__type == FLOAT) {
            return new __Base__(this.__iVal * o.__fVal);
        }

        if (this.__type == FLOAT && o.__type == INTEGER) {
            return new __Base__(this.__fVal * o.__iVal);
        }

        if (this.__type == FLOAT && o.__type == FLOAT) {
            return new __Base__(this.__fVal * o.__fVal);
        }

        if (this.__type == STRING && o.__type == INTEGER) {
            if (o.__iVal < 0) throw new IllegalArgumentException("Argument is zero");
            if (o.__iVal == 0) return new __Base__("");
            return new __Base__(new String(new char[o.__iVal]).replace("\0", this.__sVal));
        }

        if (this.__type == STRING && o.__type == FLOAT) {
            int val = (int) o.__fVal;
            if (val < 0) throw new IllegalArgumentException("Argument is zero");
            if (val == 0) return new __Base__("");
            return new __Base__(new String(new char[val]).replace("\0", this.__sVal));
        }

        throw new UnsupportedOperationException("mul isn't support operation for types: " + this.__type + " and: " + o.__type);
    }

    public __Base__ __div__(__Base__ o) {
        if (this.__type == INTEGER && o.__type == INTEGER) {
            return new __Base__(this.__iVal / o.__iVal);
        }

        if (this.__type == INTEGER && o.__type == FLOAT) {
            return new __Base__(this.__iVal / o.__fVal);
        }

        if (this.__type == FLOAT && o.__type == INTEGER) {
            return new __Base__(this.__fVal / o.__iVal);
        }

        if (this.__type == FLOAT && o.__type == FLOAT) {
            return new __Base__(this.__fVal / o.__fVal);
        }

        throw new UnsupportedOperationException("div isn't support operation for types: " + this.__type + " and: " + o.__type);
    }

    public __Base__ __mod__(__Base__ o) {
        if (this.__type == INTEGER && o.__type == INTEGER) {
            return new __Base__(this.__iVal % o.__iVal);
        }

        if (this.__type == INTEGER && o.__type == FLOAT) {
            return new __Base__(this.__iVal % o.__fVal);
        }

        if (this.__type == FLOAT && o.__type == INTEGER) {
            return new __Base__(this.__fVal % o.__iVal);
        }

        if (this.__type == FLOAT && o.__type == FLOAT) {
            return new __Base__(this.__fVal % o.__fVal);
        }

        if (this.__type == STRING) return new __Base__(this.__sVal);

        throw new UnsupportedOperationException("div isn't support operation for types: " + this.__type + " and: " + o.__type);
    }

    public __Base__ __eql__(__Base__ o) {
        if (this.__type == NIL && o.__type == NIL) return new __Base__(true);
        if (this.__type == NIL || o.__type == NIL) return new __Base__(false);

        if (this.__type == INTEGER && o.__type == INTEGER) {
            return new __Base__(this.__iVal == o.__iVal);
        }

        if (this.__type == INTEGER && o.__type == FLOAT) {
            return new __Base__(this.__iVal == o.__fVal);
        }

        if (this.__type == FLOAT && o.__type == INTEGER) {
            return new __Base__(this.__fVal == o.__iVal);
        }

        if (this.__type == FLOAT && o.__type == FLOAT) {
            return new __Base__(this.__fVal == o.__fVal);
        }

        if (this.__type == STRING && o.__type == STRING) {
            return new __Base__(this.__sVal.equals(o.__sVal));
        }

        if (this.__type == BOOLEAN && o.__type == BOOLEAN) {
            return new __Base__(this.__bVal == o.__bVal);
        }

        if (this.__type != o.__type) return new __Base__(false);

        throw new UnsupportedOperationException("eql isn't support operation for types: " + this.__type + " and: " + o.__type);
    }

    public __Base__ __les__(__Base__ o) {
        if (this.__type == INTEGER && o.__type == INTEGER) {
            return new __Base__(this.__iVal < o.__iVal);
        }

        if (this.__type == INTEGER && o.__type == FLOAT) {
            return new __Base__(this.__iVal < o.__fVal);
        }

        if (this.__type == FLOAT && o.__type == INTEGER) {
            return new __Base__(this.__fVal < o.__iVal);
        }

        if (this.__type == FLOAT && o.__type == FLOAT) {
            return new __Base__(this.__fVal < o.__fVal);
        }

        if (this.__type == STRING && o.__type == STRING) {
            int compared = this.__sVal.compareTo(o.__sVal);
            return new __Base__(compared < 0);
        }

        throw new UnsupportedOperationException("less isn't support operation for types: " + this.__type + " and: " + o.__type);
    }

    public __Base__ __les_or_eql__(__Base__ o) {
        try {
            return new __Base__(__eql__(o).__bVal || __les__(o).__bVal);
        } catch (UnsupportedOperationException e) {
            throw new UnsupportedOperationException("less_or_eqls isn't support operation for types: " + this.__type + " and: " + o.__type);
        }
    }

    public __Base__ __greater__(__Base__ o) {
        try {
            return new __Base__(!__les_or_eql__(o).__bVal);
        } catch (UnsupportedOperationException e) {
            throw new UnsupportedOperationException("greater isn't support operation for types: " + this.__type + " and: " + o.__type);
        }
    }

    public __Base__ __greater_or_eql__(__Base__ o) {
        try {
            return new __Base__(!__les__(o).__bVal);
        } catch (UnsupportedOperationException e) {
            throw new UnsupportedOperationException("greater_or_eql isn't support operation for types: " + this.__type + " and: " + o.__type);
        }
    }

    public __Base__ __not__() {
        if (this.__type == NIL) return new __Base__(true);
        if (this.__type == BOOLEAN) return new __Base__(!this.__bVal);
        return new __Base__(false);
    }
}
