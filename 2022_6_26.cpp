
#include<iostream>
#include<algorithm>
#include<time.h>
#include<string>
#include <iomanip>
using namespace std;
class student
{
public:
	void course()
	{
		float grade;
		string name[3] = { "ÊıÑ§","Ó¢Óï","C++" };
		for (int i = 0; i < 3; i++)
		{
			grade = (rand() % 9000 + 1000) / 100.0;
			cout << name[i] << " " <<fixed<< setprecision(2) << grade << endl;
		}
	}
	void friends()
	{
		int id[3] = { 3,4,5 }, j =1;
		string name[5] = { "°¬","Â×","Ò®","¸ñ","¶û" };
		for (int i = id[rand()%3];i>0; i--)
			cout << j++ << " " << name[rand() % 5] << name[rand() % 5] + name[rand() % 5]<<endl;
	}
};
int main()
{
	srand((unsigned int)time(NULL));
	student s;
	s.course();
	s.friends();
	return 0;
}
