#include <iostream>
#include <string>
#include <variant> //since C++17
using namespace std;
//The class template std::variant represents a type-safe union.
/*
int main() {
	variant<int, double, string > v; //default ctor her zaan ilk indexi dondurur.
	cout << v.index()<<'\n'; //variantta tutulan deðiþkenin index ini dondurur

}
*/

//deðiþken türü olmayan indexi okumaya çalýþýrsa exception throw eder.
/*
int main()
{
    std::variant<int, float> v{ 12 }, w;
    std::cout << std::get<int>(v) << '\n';
    w = std::get<int>(v);
    w = std::get<0>(v); // same effect as the previous line

    //holds_alternative()
    if (holds_alternative<int>(v)) {
        cout << "evet int tutuyor\n";
    }
    //  std::get<double>(v); // error: no double in [int, float]
    //  std::get<3>(v);      // error: valid index values are 0 and 1

    try
    {
        w = 42.0f;
        std::cout << std::get<float>(w) << '\n'; // ok, prints 42
        w = 42;
        std::cout << std::get<float>(w) << '\n'; // throws
    }
    catch (std::bad_variant_access const& ex)
    {
        std::cout << ex.what() << ": w contained int, not float\n";
    }
}

class Tef {
public:
    Tef(int d, int m, int y){}
};
int main() {
    //get();//reference döndürüyor. yani deðiþkken deðiþtirilebilir.

    variant<int, double, string>x{ "tefoli"s };
    get<2>(x) = "osman";
    cout << get<string>(x) << '\n';  //osman

    variant<int, string, Tef>x1( in_place_index<2>, 12,1,1996 ); //in_place_index sayesinde türün argumanlarýný doðrudan kullandim
    variant<int, string, Tef>x2( in_place_type<Tef>, 12,1,1996 ); //in_place_type sayesinde türün argumanlarýný doðrudan kullandim
}
void* checkValue(const std::variant<int, float>& v) {
    if (const int* pval = std::get_if<int>(&v))
        std::cout << "variant value: " << *pval << '\n';
    else
        std::cout << "failed to get value!" << '\n';
    return nullptr;
}
#include <variant>
#include <iostream>
//get_if():doðru is pointer döner.yanlýþ ise nullptr döner.
int main()
{
    auto check_value = [](const std::variant<int, float>& v)
    {
        if (const int* pval = std::get_if<int>(&v))
            std::cout << "variant value: " << *pval << '\n';
        else
            std::cout << "failed to get value!" << '\n';
    };

    std::variant<int, float> v{ 12 }, w{ 3.f };
    //lambda expression
    check_value(v);
    check_value(w);
    //function pointer
    checkValue(v);
    checkValue(w);

    //variant value : 12
    //failed to get value!
}
*/

//monostate()
#include <cassert>
#include <iostream>
#include <variant>

struct S
{
    S(int i) : i(i) {}
    int i;
};

int main()
{
    // Without the monostate type this declaration will fail.
    // This is because S is not default-constructible.
    std::variant<std::monostate, S> var;
    assert(var.index() == 0);

    try
    {
        std::get<S>(var); // throws! We need to assign a value
    }
    catch (const std::bad_variant_access& e)
    {
        std::cout << e.what() << '\n';
    }

    var = 42;
    std::cout << "std::get: " << std::get<S>(var).i << '\n'
        << "std::hash: " << std::hex << std::showbase
        << std::hash<std::monostate>{}(std::monostate{}) << '\n';

    //std::get: wrong index for variant
    //std::get: 42
    //std::hash : 0xffffffffffffe19f
}