//
//  main.cpp
//  biguint
//
//  Created by Cole Roberts on 1/28/25.
//

#include <iostream>
#include <limits>

using namespace std;

int secondSmallest(vector<int> arr){
    int smallest = numeric_limits<int>::max(), secondSmallest = smallest;
    for(int const & a : arr){
        if(a < smallest){
            secondSmallest = smallest;
            smallest = a;
        } else if (a < secondSmallest){
            secondSmallest = a;
        }
    }
    return secondSmallest;
}

int main1(int argc, const char * argv[]) {
    vector<int> a = {1, 2, 3, 4, 5}, b = {5, 4, 3, 2, 1}, c = {-1000, -100, -10, -1, 0, 1, 10, 100, 1000};
    cout << "Testing {1, 2, 3, 4, 5}\nSecond Smallest: " << secondSmallest(a) << endl;
    cout << "Testing {5, 4, 3, 2, 1}\nSecond Smallest: " << secondSmallest(b) << endl;
    cout << "Testing {-1000, -100, -10, -1, 0, 1, 10, 100, 1000}\nSecond Smallest: " << secondSmallest(c) << endl;
    return 0;
}

struct ModInt {
    int mod;
    int val;
    ModInt(){
        mod = numeric_limits<int>::max();
        val = 0;
    }
    ModInt(int v, int m){
        if(v > m){
            v %= m;
        }
        mod = m;
        val = v;
    }
};

int main2(int argc, const char * argv[]) {
    ModInt a = ModInt();
    ModInt b = ModInt(5, 10);
    ModInt c = ModInt(75, 50);
    cout << "Testing ModInt():\n\tmod = " << a.mod << "\n\tval = " << a.val << endl;
    cout << "Testing ModInt(5, 10):\n\tmod = " << b.mod << "\n\tval = " << b.val << endl;
    cout << "Testing ModInt(75, 50):\n\tmod = " << c.mod << "\n\tval = " << c.val << endl;
    return 0;
}

class Mod {
private:
    int mod;
    int val;
public:
    Mod(){
        mod = numeric_limits<int>::max();
        val = 0;
    }
    Mod(int v, int m){
        if(v >= m){
            v %= m;
        }
        mod = m;
        val = v;
    }
    int getVal(){
        return val;
    }
    int getMod(){
        return mod;
    }
    void setVal(int v){
        if(v > mod){
            v %= mod;
        }
        val = v;
        return;
    }
    void setMod(int m){
        if(m < val){
            val %= m;
        }
        mod = m;
        return;
    }
    void plusEquals (Mod right);
    void operator += (Mod right);
};

bool equals(Mod left, Mod right){
    if(left.getVal() == right.getVal() && left.getMod() == right.getMod()){
        return true;
    } else {
        return false;
    }
}

int main3(int argc, const char * argv[]) {
    Mod tester = Mod();
    cout << "Testing ModInt():\n\tmod = " << tester.getMod() << "\n\tval = " << tester.getVal() << endl;
    cout << "Testing setVal(5):\n\tnew val = ";
    tester.setVal(5);
    cout << tester.getVal() << endl;
    cout << "Testing setMod(10):\n\tnew mod = ";
    tester.setMod(10);
    cout << tester.getMod() << endl;
    cout << "Testing setMod(50) and setVal(75):\n\tnew val = ";
    tester.setVal(75);
    tester.setMod(50);
    cout << tester.getVal() << "\n\tnew mod = " << tester.getMod() << endl;
    Mod tester2 = Mod(75, 50);
    cout << "Testing equals function:\n\tresult for equal nums = " << equals(tester, tester2) << endl;
    return 0;
}

Mod Plus(Mod left, Mod right){
    if(left.getMod() != right.getMod()){
        return Mod(-1, -1);
    } else {
        return Mod(left.getVal() + right.getVal(), left.getMod());
    }
}

int main4(int argc, const char * argv[]) {
    Mod a = Mod(75, 50);
    Mod b = Mod(5, 50);
    cout << "Testing song tracks. On a 50 track record, if we listen to 75 songs we will be on song " << a.getVal() << " of the record. If we listen to 5 more tracks, we will be at song ";
    a = Plus(a, b);
    cout << a.getVal() << " of the record. Testing passing the mod value, we will try to skip 40 songs ahead. We are now listening to song ";
    a = Plus(a, Mod(40, 50));
    cout << a.getVal() << " of the record." << endl;
    
    return 0;
}

Mod Mult(Mod left, Mod right){
    if(left.getMod() != right.getMod()){
        return Mod(-1, -1);
    } else {
        return Mod(left.getVal() * right.getVal(), left.getMod());
    }
}

int main5(int argc, const char * argv[]) {
    Mod a = Mod(75, 50);
    Mod b = Mod(5, 50);
    cout << "Testing multiplying number. On a 50 mod number, if we give it a val of 75 songs we will be store " << a.getVal() << ". If we multiply that value by 5, we will store ";
    a = Mult(a, b);
    cout << a.getVal() << ". Testing another Mult, we will try to multiply by 40. We now have a value of ";
    a = Mult(a, Mod(40, 50));
    cout << a.getVal() << " with mod 50." << endl;
    
    return 0;
}

void Mod::plusEquals(Mod right){
    if(mod != right.getMod()){
        mod = -1;
        val = -1;
    } else {
        val += right.getVal();
        if(val > mod){
            val %= mod;
        }
    }
    return;
}

int main6(int argc, const char * argv[]) {
    Mod a = Mod(75, 50);
    cout << "Testing song tracks. On a 50 track record, if we listen to 75 songs we will be on song " << a.getVal() << " of the record. If we listen to 5 more tracks, we will be at song ";
    a.plusEquals(Mod(5,50));
    cout << a.getVal() << " of the record. Testing passing the mod value, we will try to skip 40 songs ahead. We are now listening to song ";
    a.plusEquals(Mod(40, 50));
    cout << a.getVal() << " of the record." << endl;
    
    return 0;
}

bool operator ==(Mod left, Mod right){
    return (left.getVal() == right.getVal() && left.getMod() == right.getMod());
}

int main7(int argc, const char * argv[]) {
    Mod a = Mod(75, 50);
    Mod b = Mod(75, 25);
    Mod c = Mod(75, 50);
    bool result1 = a == b;
    bool result2 = b == c;
    bool result3 = a == c;
    cout << "Testing ModInt.\na = Mod(75, 50)\nb = Mod(75, 25)\nc = Mod(75, 50)\na = b ? " << result1 << "\nb = c ? " << result2 << "\na = c ? " << result3 << "\n";
    if(!result1 && !result2 && result3){
        cout << "All tests passed!" << endl;
    } else {
        cout << "Test cases failed." << endl;
    }
    return 0;
}

void Mod::operator += (Mod right){
    if(mod != right.getMod()){
        mod = -1;
        val = -1;
    } else {
        val += right.getVal();
        if(val > mod){
            val %= mod;
        }
    }
    return;
}

int main8(int argc, const char * argv[]) {
    Mod a = Mod(75, 50);
    cout << "Testing addition of song tracks with the += operator. On a 50 track record, if we listen to 75 songs we will be on song " << a.getVal() << " of the record. If we listen to 5 more tracks, we will be at song ";
    a += Mod(5,50);
    cout << a.getVal() << " of the record. If we assume there are only 40 tracks in the record and try to skip forward 5, we will still be at song ";
    a += Mod(5,40);
    cout << a.getVal() << " of the record because we didn't know how many songs were on the record." << endl;
    
    return 0;
}

Mod operator +(Mod left, Mod right){
    if(left.getMod() != right.getMod()){
        return Mod(-1, -1);
    } else {
        return Mod(left.getVal() + right.getVal(), left.getMod());
    }
}

int main9(int argc, const char * argv[]) {
    cout << "Testing song tracks. On a 50 track record, if we listen to 75 songs we will be on song " << Mod(75, 50).getVal() << " of the record. If we listen to 5 more tracks, we will be at song ";
    cout << (Mod(75, 50) + Mod(5, 50)).getVal() << " of the record. Testing passing the mod value, we will try to skip 40 songs ahead. We are now listening to song ";
    cout << (Mod(75, 50) + Mod(5, 50) + Mod(40, 50)).getVal() << " of the record." << endl;
    return 0;
}

Mod operator * (Mod left, Mod right){
    if(left.getMod() != right.getMod()){
        return Mod(-1, -1);
    } else {
        return Mod(left.getVal() * right.getVal(), left.getMod());
    }
}

int main10(int argc, const char * argv[]) {
    cout << "Testing multiplying numbers. On a 50 mod number, if we listen to 75 songs we will be song " << Mod(75, 50).getVal() << ". If we multiply that value by 5, we be at song " << (Mod(75, 50) * Mod(5, 50)).getVal() << ". Testing another *, we will try to multiply by 40. We now have a value of " << (Mod(75, 50) * Mod(5, 50) * Mod(40, 50)).getVal() << " with mod 50." << endl;
    return 0;
}

ostream& operator <<(ostream& out, Mod right){
    out << "( Value = " << right.getVal() << ", Mod = " << right.getMod() << " )";
    return out;
}

int main11(int argc, const char * argv[]) {
    cout << "Testing ModInt << operator.\n";
    for(int i = 1; i <= 10; ++i){
        for(int j = 1; j <= 20; ++j){
            cout << Mod(j, i);
        }
    }
    return 0;
}

bool operator < (Mod left, Mod right){
    if(left.getMod() != right.getMod()){
        return false;
    } else {
        return left.getVal() < right.getVal();
    }
}

bool operator > (Mod left, Mod right){
    if(left.getMod() != right.getMod()){
        return false;
    } else {
        return left.getVal() > right.getVal();
    }
}

int main12(int argc, const char * argv[]) {
    cout << "Testing ModInt < and > operators.\n";
    for(int left = 0; left < 10; ++left){
        for(int right = 9; right >= 0; --right){
            cout << Mod(left, 10) << " < " << Mod(right, 10) << " ? " << (Mod(left, 10) < Mod(right, 10)) << "\n";
        }
    }
    for(int left = 0; left < 10; ++left){
        for(int right = 9; right >= 0; --right){
            cout << Mod(left, 10) << " > " << Mod(right, 10) << " ? " << (Mod(left, 10) > Mod(right, 10)) << "\n";
        }
    }
    return 0;
}

bool operator <= (Mod left, Mod right){
    if(left.getMod() != right.getMod()){
        return false;
    } else {
        return left.getVal() <= right.getVal();
    }
}

bool operator >= (Mod left, Mod right){
    if(left.getMod() != right.getMod()){
        return false;
    } else {
        return left.getVal() >= right.getVal();
    }
}

bool operator != (Mod left, Mod right){
    if(left.getMod() != right.getMod()){
        return true;
    } else {
        return left.getVal() != right.getVal();
    }
}

int main(int argc, const char * argv[]) {
    cout << "Testing ModInt <=, >=, and != operators.\n<= operator:\n";
    for(int left = 0; left < 10; ++left){
        for(int right = 9; right >= 0; --right){
            cout << Mod(left, 10) << " <= " << Mod(right, 10) << " ? " << (Mod(left, 10) <= Mod(right, 10)) << "\n";
        }
    }
    cout << ">= operator:\n";
    for(int left = 0; left < 10; ++left){
        for(int right = 9; right >= 0; --right){
            cout << Mod(left, 10) << " >= " << Mod(right, 10) << " ? " << (Mod(left, 10) >= Mod(right, 10)) << "\n";
        }
    }
    cout << "!= operator:\n";
    for(int left = 0; left < 10; ++left){
        for(int right = 9; right >= 0; --right){
            cout << Mod(left, 10) << " != " << Mod(right, 10) << " ? " << (Mod(left, 10) != Mod(right, 10)) << "\n";
        }
    }
    cout << endl;
    return 0;
}
