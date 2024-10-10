#ifndef TIME_H
#define TIME_H
#include <iostream>
namespace chron
{
	class Time
	{
	private:
        int TotalSecondsw;
		void normalise();
	public:
		Time()=default;
		Time(int h,int m,int s);
		int GetHours() const;
		int GetMinutes() const;
	    int GetSeconds() const;
		Time(int p):Time(0,0,p){
        }
		void AddSeconds(int s);
		Time &operator += (int s);
		int TotalSeconds() const;
	 };
}
int operator-(const chron::Time& t1,const chron::Time& t2);
std::ostream& operator<<(std::ostream& out, const chron::Time& t);
std::istream& operator>>(std::istream& in,chron::Time& t);

#endif //TIME_H

