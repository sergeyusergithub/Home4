#include "fraction.hpp"



//===========================================================
fraction::fraction(double real_num) {
    long long num_length = 100000000; // 8 + 1 количество значимых чисел после запятой
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

    round_num = round(real_num * (double)num_length);
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

    a = abs(a);
    b = abs(b);

    if (a < b) {
        std::swap(a, b);
    }

    if (a % b == 0) {
        return b;
    }

    c = a % b;

    result = NOD(b, c);
    if (result == 1) {
        return 1ll;
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
   
    int div = tmp.NOD(tmp.numerator_, tmp.denominator_);

    tmp.numerator_ /= div;
    tmp.denominator_ /= div;

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

    int div = tmp.NOD(tmp.numerator_, tmp.denominator_);

    tmp.numerator_ /= div;
    tmp.denominator_ /= div;

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

    int div = tmp.NOD(tmp.numerator_, tmp.denominator_);

    tmp.numerator_ /= div;
    tmp.denominator_ /= div;

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

    int div = tmp.NOD(tmp.numerator_, tmp.denominator_);

    tmp.numerator_ /= div;
    tmp.denominator_ /= div;

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
std::istream& operator >> (std::istream& in, fraction& fr_obj)
{
    std::string str;
   
    std::getline(in,str,'\n');
    int index = str.find('/');
    if (index < str.length()){
        try {
            fr_obj.numerator_=  std::stoi(str);
            fr_obj.denominator_ = std::stoi(str.substr(index + 1));
            fr_obj.sign_ = fr_obj.sign_fract();
        }
        catch (std::exception ex) {
            std::cout << ex.what() << std::endl;
        }
        
    }
    else {
        throw - 1;
    }
    
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
    return (long long)real_number();
}


//===============================================================
fraction fraction::fract_part()
{
    if (is_proper()) {
        return *this;
    }
    fraction tmp;
    if (numerator_ % denominator_ == 0) {
        fraction tmp1(numerator_ / denominator_);
        tmp = tmp1;
    }
    else {
        fraction tmp2(numerator_ - int_part() * denominator_, denominator_ );
        tmp = tmp2;
    }
    
    return tmp;
}

//===============================================================
fraction fraction::reverse_fract()
{
    fraction tmp(denominator_, numerator_);
    return tmp;
}







//================================================================
double fraction::real_number(){
   return numerator_*(1.0)/denominator_;
}


//================================================================
bool fraction::is_proper() {
    return abs(numerator_) >= abs(denominator_) ? false : true;
}


//===============================================================
bool fraction::is_int() {
    return ((numerator_ == denominator_) || (abs(denominator_) == 1)) ? true : false;
}


