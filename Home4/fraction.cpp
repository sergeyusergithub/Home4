#include "fraction.hpp"


//===========================================================
fraction::fraction(double real_num) {
    int num_length = 1000; // 3 + 1 количество значимых чисел после запятой
    int round_num; // целая чать действительного числа

    // начальные значения числителя и знаменателя
    numerator_ = 0;
    denominator_ = 1;

    // преобразование отрицательного вещественного числа к положительному и запись знака в поле sign_
    // для удобства работы алгоритма
    sign_ = (real_num < 0) ? true : false;
    if (sign_) {
        real_num *= -1.0;
    }

    // преобразуем все нули после запятой, до значащих чисел, в число в знаменателе
    while (real_num < 1) {
        denominator_ *= 10;
        real_num *= 10.0;
    }

    round_num = real_num * (double)num_length;
    numerator_ = round_num;
    denominator_ *= num_length; 

    long long div = NOD(numerator_, denominator_);
    numerator_ /= div;
    denominator_ /= div;

    numerator_ = (sign_ == true) ? numerator_ * (-1) : numerator_;
         
}


//================================================================
void fraction::zero_excep(long long num){
    if (num == 0){
        throw std::exception("Error: Deveder by zero");
    }
}


//================================================================
bool fraction::sign_fract(){
    if ((numerator_ > 0 && denominator_ > 0) ||
    (numerator_ < 0 && denominator_ < 0)){
        return false;
    }

    return true;
}


//=================================================================
int fraction::NOD(long long a, long long b)
{   
    long long c;
    long long result;

    if (a < b) {
        std::swap(a, b);
    }

    if (a % b == 0) {
        return b;
    }

    c = a % b;

    result = NOD(b, c);
    if (result == 1) {
        return 1;
    }
    return result;
}


//================================================================
void Sum(fraction& frac1, const fraction& frac2){
            
    frac1.numerator_ = frac1.numerator_ * frac2.denominator_ + frac2.numerator_ * frac1.denominator_;
    frac1.denominator_ *= frac2.denominator_;
    frac1.sign_ = frac1.sign_fract();
}

//================================================================
void Sum(fraction& frac, long long num)
{
    fraction tmp(num, 1);
    Sum(frac, tmp);
}

//================================================================
fraction operator+(const fraction& obj1, const fraction& obj2)
{
    fraction tmp;
    tmp.numerator_ = obj1.numerator_ * obj2.denominator_ + obj2.numerator_ * obj1.denominator_;
    tmp.denominator_ = obj1.denominator_ * obj2.denominator_;
    tmp.sign_ = tmp.sign_fract();
    return tmp;
}




//================================================================
void Multiply(fraction& frac1,const fraction& frac2)
{
    frac1.numerator_ *= frac2.numerator_;
    frac1.denominator_ *= frac2.denominator_;
    frac1.sign_ ^= frac2.sign_;
}

//================================================================
void Multiply(fraction& frac, long long num)
{
    fraction tmp(num, 1);
    Multiply(frac, tmp);
}

//================================================================
fraction operator*(const fraction& obj1, const fraction& obj2)
{
    fraction tmp;
    tmp.numerator_ = obj1.numerator_ * obj2.numerator_;
    tmp.denominator_ = obj1.denominator_ * obj2.denominator_;
    tmp.sign_ = tmp.sign_fract();
    return tmp;
}


//================================================================
void Sub(fraction& frac1,const fraction& frac2)
{
    frac1.numerator_ = frac1.numerator_ * frac2.denominator_ - frac2.numerator_ * frac1.denominator_;
    frac1.denominator_ *= frac2.denominator_;
    frac1.sign_ = frac1.sign_fract();
}

//================================================================
void Sub(fraction& frac, long long num)
{
    fraction tmp(num, 1);
    Sub(frac, tmp);
}

//================================================================
fraction operator-(const fraction& obj1, const fraction& obj2)
{
    fraction tmp;
    tmp.numerator_ = obj1.numerator_ * obj2.denominator_ - obj2.numerator_ * obj1.denominator_;
    tmp.denominator_ = obj1.denominator_ * obj2.denominator_;
    tmp.sign_ = tmp.sign_fract();
    return tmp;
}



//================================================================
void Division(fraction& frac1,const fraction& frac2)
{
    frac1.numerator_ *= frac2.denominator_;
    frac1.denominator_ *= frac2.numerator_;
    frac1.sign_ ^= frac2.sign_;
}

//================================================================
void Division(fraction& frac, long long num)
{
    fraction tmp(num, 1);
    Division(frac, tmp);
}


//================================================================
fraction operator/(const fraction& obj1, const fraction& obj2)
{
    fraction tmp;
    tmp.numerator_ = obj1.numerator_ * obj2.denominator_;
    tmp.denominator_ = obj1.denominator_ * obj2.numerator_;
    tmp.sign_ = tmp.sign_fract();
    return tmp;
}



//================================================================
fraction operator-(fraction& fr_obj) {
    fr_obj.numerator_ *= -1;
    fr_obj.sign_ = !fr_obj.sign_;
    return fr_obj;
}


//================================================================
fraction operator+(fraction& fr_obj) {
    fr_obj.numerator_ *= 1;
    fr_obj.sign_ = fr_obj.sign_;
    return fr_obj;
}


//================================================================
fraction fraction::operator++()
{
    numerator_ = numerator_ + denominator_;
    sign_ = sign_fract();
    
    return *this;
}



//================================================================
fraction fraction::operator++(int)
{   
    fraction old = *this;
    ++*this;
    return old;
}


//================================================================
fraction fraction::operator--(int) {
    fraction old = *this;
    --*this;
    return old;

}

//================================================================
fraction fraction::operator--() {
    numerator_ = numerator_ - denominator_;
    sign_ = sign_fract();

    return *this;
}

//================================================================
std::ostream& operator<<(std::ostream& out, const fraction& fr_obj)
{
    out << fr_obj.numerator_ << "/" << fr_obj.denominator_;
    return out;
}


//================================================================
std::istream& operator>>(std::istream& in,fraction& fr_obj)
{
    long long numerator, denominator;
    bool sign;
    in >> numerator >> denominator;
    fr_obj.Numerator(numerator);
    fr_obj.Denominator(denominator);
    sign = (numerator > 0 && denominator < 0 ||
        numerator < 0 && denominator > 0) ? true : false;
    fr_obj.Sign(sign);
    return in;
}





//================================================================
fraction& fraction::operator=(const fraction fr_obj)
{
    numerator_ = fr_obj.numerator_;
    denominator_ = fr_obj.denominator_;
    sign_ = fr_obj.sign_;

    return *this;
}

//===============================================================
long long fraction::int_part()
{   
    return (long long)Real_Number();
}


//===============================================================
fraction fraction::fract_part()
{
    if (proper_fraction()) {
        return *this;
    }
    fraction tmp(numerator_ - int_part()*denominator_,denominator_);
    return tmp;
}

//===============================================================
fraction fraction::reverse_fract()
{
    fraction tmp(denominator_, numerator_);
    return tmp;
}







//================================================================
float fraction::Real_Number(){
   return numerator_*(1.0)/denominator_;
}


//================================================================
bool fraction::proper_fraction() {
    return abs(numerator_) >= abs(denominator_) ? false : true;
}


//===============================================================
bool fraction::is_int() {
    return (numerator_ == denominator_) ? true : false;
}


