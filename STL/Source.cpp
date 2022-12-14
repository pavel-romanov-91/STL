#include<iostream>
#include<array>
#include<vector>
#include<deque>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define ARRAY
//#define VECTOR
#define DEQUE

typedef int DataType;

void main()
{
	setlocale(LC_ALL, "");
#ifdef ARRAY
	const int n = 5;
	std::array<int, n> arr = { 3,5,8,13,21 };
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
#endif // ARRAY

#ifdef VECTOR
	typedef int DataType;
	std::vector<DataType> vec = { 0,1,1,2,3,5,8,13,21,34 };
	try
	{
		for (int i = 0; i < vec.size() * 2; i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	for (std::vector<DataType>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::vector<DataType>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	vec.front() = 1024;
	cout << vec.front() << endl;
	cout << vec.back() << endl;

	cout << *vec.data()+4 << endl;
	cout << "---------------- Vector capacity ----------------- \n";
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "size:\t" << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	
	vec.push_back(55);
		
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "size:\t" << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	
	//vec.shrink_to_fit();	//уменьшает до фактического размепа
	//vec.resize(25);			//принудительно задает размер вектора
	vec.reserve(55);		//задает вектор и работает только для увеличения
	//vec.assign({ 1024, 2048, 3072, 4096, 5120 });
	for (int i : vec)cout << i << tab; cout << endl;	
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "size:\t" << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	//std::vector<int>::iterator position = vec.begin() + index;
	if (index < vec.size())
		vec.insert(vec.begin() + index, value);
	for (int i : vec)cout << i << tab; cout << endl;
	cout << *(vec.end() - 1) << endl;
	vec.insert(vec.begin() + 3, vec.end() - 4, vec.end() - 1);
	for (int i : vec)cout << i << tab; cout << endl;



#endif // VECTOR

#ifdef DEQUE
	std::deque<DataType>deque = { 3,5,8,13,21 };
	for (std::deque<DataType>::iterator it = deque.begin(); it != deque.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);
	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i : deque)cout << i << tab; cout << endl;
	for (std::deque<DataType>::reverse_iterator it = deque.rbegin(); it != deque.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // DEQUE


}