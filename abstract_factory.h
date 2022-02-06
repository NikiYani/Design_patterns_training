#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include <iostream>

using namespace std;

class abstract_product_type_1
{
    std::string name;
public:
    virtual ~abstract_product_type_1(){};
    virtual void print_product_name() const = 0;
};

class product_type_1_ver_A: public abstract_product_type_1
{
public:
    void print_product_name() const override
    {
        cout << "product_type_1_ver_A" << endl;
    }
};

class product_type_1_ver_B: public abstract_product_type_1
{
public:
    void print_product_name() const override
    {
        cout << "product_type_1_ver_B" << endl;
    }
};

class abstract_product_type_2
{
    std::string name;
public:
    virtual ~abstract_product_type_2(){};
    virtual void print_product_name() const = 0;
};

class product_type_2_ver_A: public abstract_product_type_2
{
public:
    void print_product_name() const override
    {
        cout << "product_type_2_ver_A" << endl;
    }
};

class product_type_2_ver_B: public abstract_product_type_2
{
public:
    void print_product_name() const override
    {
        cout << "product_type_2_ver_B" << endl;
    }
};

class abstract_factory
{
public:
    virtual abstract_product_type_1* create_product_type_1() const = 0;
    virtual abstract_product_type_2* create_product_type_2() const = 0;
    virtual ~abstract_factory(){};
};

class factory_A: public abstract_factory
{
public:
    abstract_product_type_1* create_product_type_1() const
    {
        return new product_type_1_ver_A();
    }

    abstract_product_type_2* create_product_type_2() const
    {
        return new product_type_2_ver_A();
    }
};

class factory_B: public abstract_factory
{
public:
    abstract_product_type_1* create_product_type_1() const
    {
        return new product_type_1_ver_B();
    }

    abstract_product_type_2* create_product_type_2() const
    {
        return new product_type_2_ver_B();
    }
};


#endif // ABSTRACT_FACTORY_H
