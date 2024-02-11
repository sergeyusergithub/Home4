#include <iostream>
#include "fraction.hpp"

int main(){
    setlocale(LC_ALL, "Russian");
    
    double dbl = -0.125;
    fraction f1(dbl);

    long long num = -3;

    fraction f2(num);
    
    std::cout << "Дробь задана вещественным числом: " <<  dbl << " = " << f1 << std::endl;

    std::cout << "Вывод дроби в виде вещественного числа: " << f1.real_number() << std::endl;

    std::cout << "Дробь задана целым числом: " << num << " = " << f2 << std::endl;
    
    fraction f3(1, 4);
    fraction f4;

    std::cout << "Сложение: " << f1 << " + " << f3 << " = " << f1 + f3 << std::endl;
    std::cout << "Умножение: " << f1 << " * " << f3 << " = " << f1 * f3 << std::endl;

    std::cout << "Вычитание: " << f1 << " - " << f3 << " = " << f1 - f3 << std::endl;

    std::cout << "Деление: " << f1 << " : " << f3 << " = " << f1/f3 << std::endl;

    std::cout << "Унарный минус: " << -f1 << std::endl;

    f4 = f1;
    std::cout << "Инкремент: " << f4 << " = " << ++f1 << std::endl;
    std::cout << "Целая и дробная части: " << f1 << " = " << f1.int_part() << "(" << f1.fract_part() << ")" << std::endl;
    f4 = f1;
    std::cout << "Декримент: " << f4 << " = " << --f1 << std::endl;
    std::cout << "Целая и дробная части: " << f1 << " = " << f1.int_part() << "(" << f1.fract_part() << ")" << std::endl;

    if (f1.is_proper()) {
        std::cout << f1 << "- правильная дробь" << std::endl;
    }
    else {
        std::cout << f1 << "- не правильная дробь" << std::endl;
    }

    std::cout << "Обратная дробь: (" << f1 << ")^-1 = " << f1.reverse_fract() << std::endl;

    f4 = f1.reverse_fract();
    if (f4.is_proper()) {
        std::cout << f4 << "- правильная дробь" << std::endl;
    }
    else {
        std::cout << f4 << "- не правильная дробь" << std::endl;
    }

    if (f4.is_int()) {
        std::cout << f4 << "- дробь целое число" << std::endl;
    }
    else {
        std::cout << f4 << "- дробь не целое число" << std::endl;
    }

    f4 = { 2, 2 };

    if (f4.is_int()) {
        std::cout << f4 << "- дробь целое число" << std::endl;
    }
    else {
        std::cout << f4 << "- дробь не целое число" << std::endl;
    }

    
    fraction f5(3,2);

    
    // std::cin >> f5;

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