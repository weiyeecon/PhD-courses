// I took the file Integer.h on the blackboard as reference. Add and modify some member functions. 

class Integer{
    public:
        Integer();//construct a construction function
        Integer(int dig);
        void input();//required input member function
        void output() const;//required output member function. Use const to prevent from modifying our data.
        Integer operator+(const Integer in); //Add function
        bool operator==(const Integer in);// isEqualto function()==
        bool operator!=(const Integer in);// isNotEqualTo()!=
        bool operator>=(const Integer in);//isGreatThanorEqualTo()
        bool operator<=(const Integer in);//isLessThanorEqualTo()
        bool isZero();//Question here.
        Integer operator++();//increment()++
        Integer operator--();//decrement()--
        Integer operator*(const Integer in);// Multiply()*  Question: Why add Integer here? 
        Integer operator/(const Integer in);//divide()/
        int getdig();

    private:
        int digit;

};
