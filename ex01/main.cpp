#include <iostream>
#include <cstdint>
using namespace std;
int main(){
    //uintptr_t와 reinterpret_cast 테스트
    {
        cout<<"\e[31mtest1\e[0m\n";

        //uintptr_t는 주소값을 unsignedlong으로 저장. 플랫폼에 상관없이.
        int a=10;
        uintptr_t ptr1=reinterpret_cast<uintptr_t>(&a);

        //ptr1과 (unsigned long)&a의 주소는 같다. 
        cout<<ptr1<<"\n";
        cout<<(unsigned long)&a<<"\n";

        //a주소와 (int*)ptr1은 같다.
        cout<<&a<<"\n";
        cout<< reinterpret_cast<int*>(ptr1)<<"\n";
        cout<< (int*)(ptr1)<<"\n";
        //메모리 크기가 다르면 reinterpret_cast는 작동하지 않음.
        // cout<< reinterpret_cast<char>(ptr1)<<"\n";
        // cout<< reinterpret_cast<unsigned int>(ptr1)<<"\n";
        cout<< (int)ptr1<<"\n";
    }{
        cout<<"\e[31mtest2\e[0m\n";
        int b=10;
        uintptr_t ptr2;
        ptr2 = reinterpret_cast<uintptr_t>(&b);
        std::cout<<ptr2<<"\n";

    }{
        cout<<"\e[31mtest3\e[0m\n";
        int test=100;
        // std::cout<<reinterpret_cast<long>(test);

    }

    // std::cout<< ptr1+ptr2<<"\n";


}