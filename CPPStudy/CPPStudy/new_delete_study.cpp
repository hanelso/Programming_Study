#include"main.h"

void test_new_delete(void)
{
	int* p = new int;		// int���� heap������ �Ҵ��� �ް�, �ش� �ּҰ��� int* p�� assign�Ѵ�.

	*p = 10;

	std::cout << *p << std::endl;

	delete p;				// p�� �Ҵ���� heap ������ �޸� ������ �����Ѵ�.

	// new�� �̿��Ͽ� array�� �Ҵ� �޾� ����.
	int arr_size;
	std::cout << "array size : ";
	std::cin >> arr_size;

	// int�� ������ arr_size��ŭ heap������ �Ҵ�޴´�.
	// �Ҵ� ���� ������ �ּҰ��� int*�� list�� �Ѱ��ش�.
	int* list = new int[arr_size];			

	for (int i = 0; i < arr_size; i++)
	{
		// list ������ �� �迭�� �μ��� ���� �Է¹޴´�.
		std::cin >> list[i];
	}

	// ���
	for (int i = 0; i < arr_size; i++)
	{
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}

	// int�� �迭�� �Ҵ��� ������ delete[] �� ������ �ؾ��Ѵ�.
	delete[] list;			
}

