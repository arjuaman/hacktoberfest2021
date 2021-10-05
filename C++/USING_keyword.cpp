#include <iostream>

using namespace std;
namespace name1{
    double x=4.56;
    int m=100;

    namespace name2{               //nesting namespace
        double y = 1.23;
    }
}
namespace name3{                         //unnamed namespace
    int m=200;
    int n=300;
}
int main()
{
    using namespace name1;  //bringing members of namespace name1
    cout<<"x = "<<x<<"\n";  //x is not qualified
    cout<<"m = "<<m<<"\n";
    cout<<"y = "<<name2::y<<"\n"; //y is qualified

    using namespace name3::n; //bringing n to current scope
    cout<<"m = "<<m<<"\n";    //m is qualified
    cout<<"n = "<<n<<"\n";    //n is not qualified

    return 0;
}
