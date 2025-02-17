#pragma once

typedef enum {
    NOTYPE, // 0
    FUNCTION, // 1
    VARIABLE, // 2
    COMMAND_TYPE,
} Types;

// VARIABLES TYPES
typedef enum{
    TYPE_NOTYPE,
    TYPE_STRING,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
} VariablesTypes;

char * get_name(VariablesTypes vt){
    switch (vt)
    {
    case TYPE_STRING:
        return "string";
        break;
    case TYPE_INT:
        return "int";
        break;
    case TYPE_FLOAT:
        return "float";
        break;
    case TYPE_DOUBLE:
        return "double";
        break;
    default:
        return "Not variable type";
        break;
    }
}