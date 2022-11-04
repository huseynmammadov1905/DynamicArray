



#include <iostream>
#include <assert.h>

using namespace std;

//Task 
// Class DynamicArray (template<class t>)
// Example: DynamicArray<double> da;
// Copy Constructor, Copy Assignment operator, Default Constructor
// [] operator overloading
// AddElementToEnd
// AddElementToHead
// AddElementByIndex
// DeleteElementByIndex
// Print()

template<class T>
class DynamicArray {
	T* arr = nullptr;
	int size = 0;

public:

	DynamicArray() = default;

	DynamicArray(const DynamicArray& obj) {
		this->size = obj.size;
		delete[] arr;
		arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	~DynamicArray() {
		delete[] arr;
	}

	void Print() {
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	double GetArr() const { return arr; }

	int GetSize()const { return size; }

	void SetArr(const double* arr) {
		delete[] this->arr;
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = arr[i];
		}
	}

	void SetSize() {
		this->size = size;

	}


	DynamicArray& operator=(const DynamicArray& obj) {
		SetArr(obj.arr);
		SetSize(obj.size);
	}

	DynamicArray& operator[](int index) {
		assert(0 <= index && index < size);
		return arr[index];
	}

	void AddElementToEnd(const T& element) {
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}

		temp[size] = element;
		delete[] arr;
		arr = temp;
		size++;
		temp = nullptr;
	}



	void AddElementToHead(const T& element) {
		T* temp = new T[size + 1];
		temp[0] = element;
		for (int i = 0; i < size; i++)
		{
			temp[i + 1] = arr[i];
		}

		delete[] arr;
		arr = temp;
		size++;
		temp = nullptr;
	}

	void AddElementByIndex(const T& element, int index) {
		T* temp = new T[size + 1];
		int i = 0;
		for (; i < index; i++)
		{
			temp[i] = arr[i];
		}


		temp[index] = element;

		int j = index;
		for (; j < size; j++)
		{
			temp[j + 1] = arr[i];
		}

		delete[] arr;
		arr = temp;
		size++;
		temp = nullptr;
	}

	void DeleteElementByIndex(int index) {
		T* temp = new T[size - 1];

		int i = 0;
		for (; i < index; i++)
		{
			temp[i] = arr[i];
		}

		for (int j = index + 1; j < size; j++)
		{
			temp[j - 1] = arr[i + 1];
		}
		delete[] arr;
		arr = temp;
		size--;
		temp = nullptr;
	}
};

int main() {

	DynamicArray<int> da;
	da.AddElementToHead(1);
	da.AddElementToEnd(2);
	da.AddElementByIndex(11, 1);
	da.Print();
	da.DeleteElementByIndex(1);
	da.Print();
}