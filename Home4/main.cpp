#include <iostream>
#include "fraction.hpp"

int main(){
    setlocale(LC_ALL, "Russian");
    
    double dbl = -0.75;
    fraction f1(dbl);

    long long num = -3;

    fraction f2(num);
    
    std::cout << dbl <<  " = " << f1.Numerator() << "/" << f1.Denominator() << std::endl;

    std::cout << f1.real_number() << std::endl;

    std::cout << num << "= " << f2.Numerator() << "/" << f2.Denominator() << std::endl;
    
    fraction f3(1, 4);

    fraction f4;

    f4 = f1 + f3;

    f4 = -f1;

    --f4;



    std::cout << f3.Numerator() << "/" << f3.Denominator() <<
        " = " << f3.real_number() << std::endl;

    std::cout << f4 << " = " << f4.real_number() << std::endl;

    fraction f5(3,2);

    
    std::cin >> f5;

    std::cout << f5 << std::endl;
    std::cout << f5.int_part() << std::endl;
    std::cout << f5.fract_part() << std::endl;

    std::cout << f5.reverse_fract() << std::endl;





    // проверка если дробь создается с 0 знаминателем, то бросается исключение
    try {
        fraction f3(1, 0);
    }
    catch (std::exception ex) {
        std::cout << ex.what();
        return 1;
    }  

    return 0;
}