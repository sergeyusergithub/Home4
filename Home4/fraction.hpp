#pragma once

#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

// класс дробь
// раз нет публичных методов get и set, то
// большинство методов для вычисления используется в виде дружественных функций


class fraction {
public:

// конструктор по умолчанию
fraction():numerator_(0),denominator_(1),sign_(false){}

// конструктор с двумя параметрами
// числитель и знаменатель 
fraction(long long num,long long deno):numerator_(num),
            denominator_(deno){
    zero_excep(deno);
    this->sign_ = sign_fract();
}

// конструктор для создания дроби из целого числа
fraction(long long integer) :numerator_(integer), denominator_(1) {
    sign_fract();
}

// конструктор для создания дроби из целого числа
fraction(int integer) :numerator_(integer), denominator_(1) {
    sign_fract();
}

// конструктор для создания дроби из действительного числа
fraction(double num);

// геттеры и сеттеры

long long Numerator() const {
    return numerator_;
}

void Numerator(long long num) {
    numerator_ = num;
}

long long Denominator() const {
    return denominator_;
}

void Denominator(long long denom) {
    denominator_ = denom;
}

bool Sign() const {
    return sign_;
}

void Sign(bool sig) {
    sign_ = sig;
}
// оператор =
fraction& operator=(const fraction fr_obj);



// метод суммы двух дробей
friend void Sum(fraction& frac1, const fraction& frac2);

// метод сложения дроби и целого числа
friend void Sum(fraction& frac, long long num);

// оператор +
friend fraction operator+(const fraction& obj1,const fraction& obj2);




// метод произведения двух дробей
friend void Multiply(fraction& frac1, const fraction& frac2);

// метод произведения дроби и целого числа
friend void Multiply(fraction& frac, long long num);

// оператор *
friend fraction operator*(const fraction& obj1, const fraction& obj2);




// метод разности двух дробей
friend void Sub(fraction& frac1,const  fraction& frac2);

// метод разности дроби и целого числа
friend void Sub(fraction& frac, long long num);

// оператор -
friend fraction operator-(const fraction& obj1, const fraction& obj2);



// метод деления двух дробей
friend void Division(fraction& frac1,const  fraction& frac2);

// метод деления дроби и целого числа
friend void Division(fraction& frac, long long num);

// оператор /
friend fraction operator/(const fraction& obj1, const fraction& obj2);


// оператор унарный -
friend fraction operator-(fraction& fr_obj);


// оператор унарный +
friend fraction operator+(fraction& fr_obj);


// оператор инкремент постфиксная форма
fraction operator++(int);

// оператор инкремент перфексная форма
fraction operator++();


// оператор декремент постфиксная форма
fraction operator--(int);

// оператор декремент перфексная форма
fraction operator--();

// оператор потока вывода
friend std::ostream& operator << (std::ostream& out,const fraction& fr_obj);

// оператор потока ввода
friend std::istream& operator >> (std::istream &in,const fraction& fr_obj);

// опеределение целой части дроби
long long int_part();

// определение дробной части дроби
fraction fract_part();


// метод получения обратной дроби
fraction reverse_fract();


// метод возвращающий действительное число дроби
double real_number(); 

// метод определяющий состояние правильности дроби
// false - дробь не правильная
// ture - дробь правильная
bool is_proper(); 
                    

// метод определяющий является ли дробь целым числом
bool is_int();


private:
long long numerator_; // числитель
long long denominator_; // знаменатель
bool sign_; //знак дроби false - положительный
            // true - отрицаетльный
// метод проверки знаменателя на 0 и бросающая исключение
void zero_excep(long long num);

// метод определяющий знак дроби
bool sign_fract();

// метод вычисления НОД
int NOD(long long num1, long long num2);
};





#endif //FRACTION_HPP