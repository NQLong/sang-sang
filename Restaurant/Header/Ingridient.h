#ifndef DFFF37D2_7DC2_4F17_9AAC_2ED43460EE47
#define DFFF37D2_7DC2_4F17_9AAC_2ED43460EE47

#include "Constraint.h"

class Ingridient
{
private:
    string name;
    string measure_unit;
    double stock;
    bool available = true;



public:
    Ingridient();
    Ingridient(string, string, double);
    Ingridient(string, string, double, bool);
    Ingridient(const Ingridient &);
    Ingridient &operator=(const Ingridient &);

    static Ingridient input_ingridient();

    string getName();
    string getMeasure_unit();
    double getStock();

    void modify();

    void setName(string);
    void setMeasureUnit(string);
    void setStock(double);
    bool isAvailable();
    void setAvailable(bool available);

    friend ostream &operator<<(ostream &, const Ingridient &);
    
    friend bool operator==(const Ingridient &lhs, const Ingridient &rhs);
};

#endif /* DFFF37D2_7DC2_4F17_9AAC_2ED43460EE47 */
