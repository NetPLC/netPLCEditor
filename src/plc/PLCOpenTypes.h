#ifndef PLCOPENTYPES_H
#define PLCOPENTYPES_H

namespace PLCopen
{
    typedef struct
    {
        const char* var;
        const char* display;
    }DisplayVar;

    typedef enum
    {
        SYNTAXELEMENT,
        SYNTAXATTRIBUTE,
        SIMPLETYPE,
        COMPLEXTYPE,
        COMPILEDCOMPLEXTYPE,
        ATTRIBUTESGROUP,
        ELEMENTSGROUP,
        ATTRIBUTE,
        ELEMENT,
        CHOICE,
        ANY,
        TAG,
        CONSTRAINT,
    }XMLType;
}


#endif // PLCOPENTYPES_H
