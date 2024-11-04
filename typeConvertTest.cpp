#include <iostream>
#include <string>
using namespace std;
class Water{
	private:
		int _ml;
	public:
		Water(int ml):_ml(ml){};
		virtual ~Water(){};
		void showInfo(){
			cout<<_ml<<"mL\n";
		};
};
class SparklingWater:public Water{
	private:
		int	_ph;
	public:
		SparklingWater(int ml,int ph):Water(ml),_ph(ph){};
		virtual ~SparklingWater(){};
		void showInfo(){
			Water::showInfo();
			cout<<_ph<<"ph\n";
		};
};

int main(){
	//static_cast는 컴파일타임에서 형변환이 가능한지 검사해줌. 기본자료형끼리는 당연히 가능, 상속관계에서 부모에서 자식으로 자식에서 부모로 형변환을 지원. 하지만 안전하지 않다.

	//기본자료형 형변환
	//큰 메모리->작은메모리
	{
		double d=123123123123123123;
		cout<<static_cast<int>(d)<<"\n";
	}
	//작은메모리->큰메모리
	{
		char c='h';
		cout<<static_cast<int>(c)<<"\n";
		cout<<"\n";
	}
	//////////////////////////

	//부모<->자식간 형변환 지원.
	{
		Water* water1= new SparklingWater(100,15);
		SparklingWater* sp=static_cast<SparklingWater*>(water1);
		sp->showInfo();cout<<"\n";
	}
	//////////////////////////

	//부모 부분만 메모리를 할당했는데 static_cast로 자식으로 형변환이 가능함.안전하지 않음.
	{
		Water* water2= new Water(100);
		SparklingWater* sp2=static_cast<SparklingWater*>(water2);
		sp2->showInfo();cout<<"\n";
	}
	//////////////////////////

	//그래서 상속관계에서는 dynamic_cast를 사용. 런타임시 안전성을 검증해줌.
	{
		//virtual이 없으면 밑에 코드는 에러를 띄운다
		Water* water1= new SparklingWater(100,15);
		SparklingWater* sp;
		if ((sp=dynamic_cast<SparklingWater*>(water1))){
			sp->showInfo();cout<<"\n";
		}else{
			cout<<"dynamic_cast filaed!\n";
		}
		
		Water* water2= new Water(100);
		SparklingWater* sp2;
		if ((sp2=dynamic_cast<SparklingWater*>(water2))){
			sp2->showInfo();cout<<"\n";
		}else{
			cout<<"dynamic_cast failed!\n";
		}
	}
	//reinterpret_cast: 포인터/참조와 관련된 형변환을 지원
	{
		//이런게 가능
		Water* water=new Water(100);
		int *waterToint = reinterpret_cast<int*>(water);
	}
	{
		//근데 쓸 데 없어보이는데 어디에 사용?
		//ex01참고. C처럼 주소값을 가지고 놀 수 있다.
		int num = 0x01020304;
		char *ptr = reinterpret_cast<char *>(&num);
		if (*ptr == 0x04){
			cout<< "Little endian!\n";
		}else if (*ptr == 0x010){
			cout<< "Big endian!\n";
		}
	}
	return 0;
}