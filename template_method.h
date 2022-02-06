#ifndef TEMPLATE_METHOD_H
#define TEMPLATE_METHOD_H

#include <iostream>

using namespace std;

class abstract_class
{
public:
    virtual ~abstract_class(){}
    void template_method()
    {
        this->base_func_1();
        this->base_func_2();
        this->modif_func_1();
        this->modif_func_2();
        this->modif_func_3();
        this->hook_1();
        this->hook_2();
    }

protected:
    void base_func_1() const
    {
        cout << "base_func_1" << endl;
    }

    void base_func_2() const
    {
        cout << "base_func_2" << endl;
    }

    void base_func_3() const
    {
        cout << "base_func_3" << endl;
    }

    virtual void modif_func_1() const = 0;
    virtual void modif_func_2() const = 0;
    virtual void modif_func_3() const = 0;

    virtual void hook_1() const
    {
        cout << "hook_1_abs" << endl;
    }

    virtual void hook_2() const
    {
        cout << "hook_1_abs" << endl;
    }
};

class conc_class_A: public abstract_class
{
protected:
    virtual void modif_func_1() const override
    {
        cout << "modif_func_1_A" << endl;
    }

    virtual void modif_func_2() const override
    {
        cout << "modif_func_2_A" << endl;
    }

    virtual void modif_func_3() const override
    {
        cout << "modif_func_3_A" << endl;
    }
};

class conc_class_B: public abstract_class
{
protected:
    virtual void modif_func_1() const override
    {
        cout << "modif_func_1_B" << endl;
    }

    virtual void modif_func_2() const override
    {
        cout << "modif_func_2_B" << endl;
    }

    virtual void modif_func_3() const override
    {
        cout << "modif_func_3_B" << endl;
    }
};

#endif // TEMPLATE_METHOD_H
