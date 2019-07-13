#include"main.h"

void test_new_delete(void)
{
	int* p = new int;		// int값을 heap영역에 할당을 받고, 해당 주소값을 int* p에 assign한다.

	*p = 10;

	std::cout << *p << std::endl;

	delete p;				// p에 할당받은 heap 영역의 메모리 공간을 해제한다.

	// new를 이용하여 array를 할당 받아 보자.
	int arr_size;
	std::cout << "array size : ";
	std::cin >> arr_size;

	// int형 공간을 arr_size만큼 heap영역에 할당받는다.
	// 할당 받은 공간의 주소값을 int*형 list에 넘겨준다.
	int* list = new int[arr_size];			

	for (int i = 0; i < arr_size; i++)
	{
		// list 변수의 각 배열의 인수에 값을 입력받는다.
		std::cin >> list[i];
	}

	// 출력
	for (int i = 0; i < arr_size; i++)
	{
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}

	// int형 배열을 할당을 받으면 delete[] 로 해제를 해야한다.
	delete[] list;			
}

