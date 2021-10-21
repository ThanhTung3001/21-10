#include<iostream>
#include <fstream>
using namespace std;
#define MAX_SIZE 101
struct Student
{
	int ID;
	string fullName;
	string birthDay;
	float math;
	float physics;
	float chemistry;
	float GPA;
	//ID, full name, birthday, Math, Physics, Chemistry and GPA
};
typedef Student Student;
class Queue
{
private:
	Student A[MAX_SIZE];
	int front, rear;
public:
	// Constructor - set front and rear as -1. 
	// We are assuming that for an empty Queue, both front and rear will be -1.
	Queue()
	{
		front = -1;
		rear = -1;
	}

	// To check wheter Queue is empty or not
	bool IsEmpty()
	{
		return (front == -1 && rear == -1);
	}

	// To check whether Queue is full or not
	bool IsFull()
	{
		return (rear + 1) % MAX_SIZE == front ? true : false;
	}

	// Inserts an element in queue at rear end
	void Enqueue(Student x)
	{

		if (IsFull())
		{
			cout << "Error: Queue is Full\n";
			return;
		}
		if (IsEmpty())
		{
			front = rear = 0;
		}
		else
		{
			rear = (rear + 1) % MAX_SIZE;
		}
		A[rear] = x;
	}

	// Removes an element in Queue from front end. 
	void Dequeue()
	{
		cout << "Dequeuing \n";
		if (IsEmpty())
		{
			cout << "Error: Queue is Empty\n";
			return;
		}
		else if (front == rear)
		{
			rear = front = -1;
		}
		else
		{
			front = (front + 1) % MAX_SIZE;
		}
	}
	// Returns element at front of queue. 
	Student Front()
	{
		if (front == -1)
		{
			cout << "Error: cannot return front from empty queue\n";
		
		}
		return A[front];
	}
	/*
	   Printing the elements in queue from front to rear.
	   This function is only to test the code.
	   This is not a standard function for Queue implementation.
	*/
	void Print()
	{
		// Finding number of elements in queue  
		int count = (rear + MAX_SIZE - front) % MAX_SIZE ;
		cout << "Queue: ";
		for (int i = 0; i < count; i++)
		{
			int index = (front + i) % MAX_SIZE; // Index of element while travesing circularly from front
			getStudent(A[index]);
		}
		cout << "\n\n";
	}
	/*
	   Printing the elements in queue from front to rear.
	   This function is only to test the code.
	   This is not a standard function for Queue implementation.
	*/
	void getStudent(Student s) {
		cout << endl;
		cout << "ID: " << s.ID << " Full name: " << s.fullName << " Birth day: " << s.birthDay << " Math:" << s.math << " Phisics " << s.physics << " Chemistry: " << s.chemistry << " GPA: " << s.GPA << endl;
	}
	void readFromFile(char fileName[30]) {
		ifstream myfile;
		myfile.open(fileName);
		if (!myfile) {
			cout << "File not created!";
		}
		else {
			while (!myfile.eof())
			{
				Student st;
				myfile >> st.ID >> st.fullName >> st.birthDay >> st.math >> st.physics >> st.chemistry >> st.GPA;
				Enqueue(st);
			}
			myfile.close();
			Print();
		}
	}
	void addToFile(char fileName[30]) {
		ofstream MyFile(fileName);
		for (int i = 0; i < 2; i++)
		{
			Student st;
			cout << "ID: "; cin >> st.ID;
			cout << "Full name: "; cin >> st.fullName;
			cout << "Birth day: "; cin >> st.birthDay;
			cout << "Math: "; cin >> st.math;
			cout << "Physics: "; cin >> st.physics;
			cout << "Chemistry: "; cin >> st.chemistry;
			st.GPA = (st.physics + st.math + st.chemistry) / 3;
			MyFile << st.ID << " " << st.fullName << " "
				<< st.birthDay << " "
				<< st.math << " "
				<< st.physics << " "
				<< st.chemistry << " "
				<< st.GPA << endl;
		}
		MyFile.close();
	}
};
int main() {
	Queue q;
	char file[30] = "input.txt";
	//q.addToFile(file);
	q.readFromFile(file);
	
	return 0;
}