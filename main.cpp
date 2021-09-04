#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct MathematicalVector {
    double x=0, y=0;
};

MathematicalVector Add(const MathematicalVector& rhs, const MathematicalVector& lhs) {
    return {rhs.x + lhs.x, rhs.y + lhs.y};
}

MathematicalVector Subtract(const MathematicalVector& rhs, const MathematicalVector& lhs) {
    return {rhs.x - lhs.x, rhs.y - lhs.y};
}

MathematicalVector Scale(const MathematicalVector& v, double scalar) {
    return {v.x * scalar, v.y * scalar};
}

double Length(const MathematicalVector& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

void Normalize(MathematicalVector& v) {
    double length = Length(v);
    if (length == 0) {
        cerr << "Conversion is not possible" << endl;
        return;
    }
    v = {v.x / length, v.y / length};
}

int main() {
    string command;
    cin >> command;
    if (command == "add" || command=="subtract") {
        MathematicalVector rhs, lhs;
        MathematicalVector result;
        cout << "Enter coordinate of vector one x and y: ";
        cin >> rhs.x >> rhs.y;
        cout<<"Enter coordinate of vector two x and y: ";
        cin>>lhs.x>>lhs.y;
        if(command=="add")result=Add(rhs, lhs);
        else result= Subtract(rhs, lhs);
        cout<<"answer ("<<result.x<<", "<<result.y<<')';
    }
    else if(command=="scale"){
        MathematicalVector v;
        double scalar;
        MathematicalVector result;
        cout<<"Enter coordinate of vector x and y: ";
        cin>>v.x>>v.y;
        cout<<"Enter scalar: ";
        cin>>scalar;
        result= Scale(v, scalar);
        cout<<"answer ("<<result.x<<", "<<result.y<<')';
    }
    else if(command=="length"){
        MathematicalVector v;
        cout<<"Enter coordinate of vector x and y: ";
        cin>>v.x>>v.y;
        cout<<"Length of the vector is: "<<Length(v);
    }
    else if(command=="normalize"){
        MathematicalVector v;
        cout<<"Enter coordinate of vector x and y: ";
        cin>>v.x>>v.y;
        Normalize(v);
        cout<<"Normalized vector: ("<<v.x<<", "<<v.y<<')';
    }
    else cerr<<"Unknown command"<<endl;
    return 0;
}
