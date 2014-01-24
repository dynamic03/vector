// I did the extra credit, Please check it :)

#include <assert.h>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <assert.h>


using namespace std;

template<class T>
class myvector
{
public:
	myvector();// default constructor
	myvector(int length); //define size as length
	myvector(T *arr, int length);
	myvector( const myvector &); // copy constructor
	const myvector& operator=(const myvector&); // operator=
	~myvector();	T& operator[](int);
	const T& operator[](int) const;
	T& at(int index);
	//////////////////////////////////////////////////////////////////////////////
	int size() const; // return the current length of the vector
	int capacity() const; // return the current capacity of the vector
	bool empty() const; // return whether or not the vector is empty
	void resize(int); // resize the vector (change length) to the specified size, changing capacity as needed
	void reserve(int); // change the vector capacity to the specified size, or give an error if capacity would get smaller than length
	void assign(int, T const &); // assign the second argument as the value of the vector at the position of the first argument
	void push_back(T const &); // increase length by 1 and add the argument as the value at the end
	T pop_back(); // decrease length by 1, returning the value removed from the vector
	void insert(int, T const &); // increase length by 1, put the value specified in the second argument at index specified by first argument and shift all values to the right in the vector down by one index
	void erase(int); // decrease length by 1, remove the item at the specified index, and shift all other =items left to eliminate the "hole"
	void erase(int, int); // same as erase(int), but removes all elements between the indexes specified by the first and second argument
	void clear(); // remove all elements from the list

private:
	T *array;
	int _size;//its length
	int _capacity;
};

template<class T>
myvector<T>::myvector()
{
	array=new T[10];
	_size=0;
	_capacity=10;
}

template<class T>
myvector<T>::myvector(int length)
{
	array=new T[length*2+1];
	_size=length;
	_capacity=length*2+1;
}

template<class T>
myvector<T>::myvector(T *arr, int length)
{
	array=new T[length*2+1];
	_size=length;
	for(int i=0;i<length;i++)
		array[i]=arr[i];
	_capacity=length*2+1;
}


template<class T>
const myvector<T>& myvector<T>:: operator=(const myvector<T> &ob)
{
	if(this !=&ob)
	{
		delete[] array;
		array=new T[ob._capacity];
		for(int i=0;i<ob._size;i++)
			array[i]=ob.array[i];
		_size=ob._size;
		_capacity=ob._capacity;
	}
	return *this;
}

template<class T>
myvector<T>::myvector(const myvector<T> &ob)
{
	array=new T[ob._capacity];
	for(int i=0;i<ob._size;i++)
		array[i]=ob.array[i];
	    _size=ob._size;
		_capacity=ob._capacity;
}

template<class T>
myvector<T>::~myvector()
{
	delete[] array;
}


template<class T>
T& myvector<T>::operator[](int index)
{
	if(index<0||index>=_size)
		throw overflow_error("Overflow error!");
	return array[index];
}

template<class T>
const T& myvector<T>::operator[](int index) const
{
	if(index<0||index>=_size)
	throw overflow_error("Overflow error!");
	return array[index];
}

template <class T>
T& myvector<T>::at(int index)
{
	if(index<0||index>=_size)
	throw overflow_error("Overflow error!");
	return array[index];
}

template <class T>
int myvector<T>::size() const
{
	return _size;
}

template<class T>
int myvector<T>::capacity() const
{
	return _capacity;
}

template<class T>
bool myvector<T>::empty() const
{
	if(_size==0) return true;
	else return false;
}

template<class T>
void myvector<T>::resize(int _resize)
{
	if(_resize>_capacity) reserve(_resize*2+1);
	_size=_resize;
}

template<class T>
void myvector<T>::reserve(int _recapacity)
{
	if(_size>_recapacity) throw overflow_error("Overflow error!");
	T *oldArray=array;
	int numberToCopy=_capacity;
	array=new T[_recapacity];
	for(int i=0;i<numberToCopy;i++)
		array[i]=oldArray[i];
	_size=numberToCopy;
	_capacity=_recapacity;
	delete[] oldArray;
}


template<class T>
void myvector<T>::assign(int num, const T &element)////????
{
	if(num<0 || num>=_size) throw overflow_error("Overflow error!");
		array[num]=element;
}

template<class T>
void myvector<T>::push_back(T const &element)
{
	if(_size==_capacity) reserve( 2 *_capacity + 1 );
	array[_size++]=element;
}

template<class T>
T myvector<T>::pop_back()
{
	if(_size==0) throw overflow_error("Overflow error!");
	_size--;
	return array[_size];
}

template<class T>
void myvector<T>::insert(int index, T const & newElement)
{
	if(_size==_capacity) reserve(2*_capacity+1);
	if(index>=_size||index<0) throw overflow_error("Overflow error!");
	else 
	{
		for(int i=_size-1;i>=index;i--)
			array[i+1]=array[i];
		array[index]=newElement;
		_size++;
	}	

}

template<class T>
void myvector<T>::erase(int index)
{
	
	if(index<0||index>=_size) throw overflow_error("Overflow error!");	
	_size--;
	while(index<_size)
	{
		array[index]=array[index+1];
		index++;
	}	
}

template<class T>
void myvector<T>::erase(int begin, int end)
{
	if(begin<0||begin>=_size||end<0 || end>=_size||begin>end)
		throw overflow_error("Overflow error!");
	
	for(int i=0;i<_size-(end-begin)-1;i++)
	{
		array[begin+i]=array[end+1+i];
	}
	_size=_size-(end-begin)-1;
}

template<class T>
void myvector<T>::clear()
{
	while(!empty())
		pop_back();
}

void main()
{
	
	int h[]={1,2,3,4,5,6,7,8,9,10};
	myvector<int> d(h,10);
	myvector<int> vx;
	vx=d;
	for(int i=11;i<21;i++)
		vx.push_back(i);
	cout<<vx.at(5);
	cout<<endl;
	vx.insert(2,1000);
	
	for(int i=0;i<vx.size();i++)
	cout<<vx[i]<<" ";
		cout<<endl;
		vx.erase(2);
	for(int i=0;i<vx.size();i++)
	cout<<vx[i]<<" ";
	cout<<endl;
	try
	{
		vx.assign(10,1);
	cout<<vx.size()<<endl;
	}
	catch(overflow_error)
	{
		cout<<"dfg3";
	}
	cout<<endl;
	while(!vx.empty())
	cout<<vx.pop_back()<<" ";
	
    vx.clear();
}