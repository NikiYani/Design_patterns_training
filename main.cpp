#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>

#include "abstract_factory.h"
#include "adapter.h"
#include "template_method.h"

void abstract_factory_play()
{
    cout << "abstract_factory_play:" << "\n\n";

    factory_A *fac_a = new factory_A();
    factory_B *fac_b = new factory_B();

    abstract_product_type_1 *product_type_1_a = fac_a->create_product_type_1();
    abstract_product_type_2 *product_type_2_a = fac_a->create_product_type_2();

    abstract_product_type_1 *product_type_1_b = fac_b->create_product_type_1();
    abstract_product_type_2 *product_type_2_b = fac_b->create_product_type_2();

    product_type_1_a->print_product_name();
    product_type_2_a->print_product_name();
    product_type_1_b->print_product_name();
    product_type_2_b->print_product_name();

    cout << endl;

    delete product_type_1_a;
    delete product_type_2_a;
    delete product_type_1_b;
    delete product_type_2_b;

    delete fac_a;
    delete fac_b;
}

void adapter_play()
{
    cout << "adapter_play:" << "\n\n";

    Target *target = new Adapter(new Adaptee());
    Adaptee *adaptee = new Adaptee();

    vector<int> nums;

    srand(time(0));

    int m = 5 + rand() % 100;

    for(int i = 0; i < m; i++)
    {
        nums.push_back(rand() % 50);
    }

    cout << "search result: " << adaptee->search_in_vector(nums, rand() % 50) << endl;
    cout << "search result with adapter: " << target->search_in_vector(nums, rand() % 50) << endl;

    cout << endl;

    delete adaptee;
    delete target;
}

void template_method_play()
{
    cout << "template_method_play:" << "\n\n";

    abstract_class *ptr_abs_a = new conc_class_A();
    ptr_abs_a->template_method();
    delete ptr_abs_a;

    cout << endl;

    abstract_class *ptr_abs_b = new conc_class_B();
    ptr_abs_b->template_method();
    delete ptr_abs_b;

    cout << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "design_patterns_training_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    abstract_factory_play();
    adapter_play();
    template_method_play();

    return a.exec();
}
