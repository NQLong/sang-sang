// #include <string>
// #include <iostream>
// #include <iomanip>
// #include <ctime>
// #include <list>

// using namespace std;

// class A
// {
// public:
//     int a;
//     int b;

// public:
//     A(){};
//     ~A() {}
//     A(int _a, int _b) : a(_a), b(_b) {}
//     friend bool operator==(const A &lhs, const A &rhs)
//     {
//         return ((lhs.a == rhs.a) && (lhs.b == rhs.b));
//     }
// };

// int main()

// {
//     list<A> lst = {
//         A(1, 2),
//         A(3, 4),
//         A(5, 6),
//         A(7, 8),
//     };
//     lst.remove(*(&*lst.begin()));

//     for (auto it = lst.begin(); it != lst.end(); it ++){
//         cout<<it->a<<" "<<it->b<<endl;
//     }
// }