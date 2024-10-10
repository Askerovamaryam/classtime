#include <iostream>
#include "time.h"
using namespace chron;

int Time::GetHours() const 
{
	return TotalSecondsw/3600;
}
int Time::GetMinutes() const
{
	return (TotalSecondsw % 3600)/60;
}
int Time::GetSeconds() const
{
	return TotalSecondsw % 60;
} 
void Time::AddSeconds(int s)
{
	TotalSecondsw+=s;
	normalise();
}
int Time::TotalSeconds() const
{
	return TotalSecondsw;
}
Time::Time(int h, int m, int s)
{
	TotalSecondsw=3600*h+60*m+s;
	normalise();
}
void Time::normalise()
{
 TotalSecondsw %= 24*3600;
 if(TotalSecondsw<0)
 {
	 TotalSecondsw += 24*3600;
 }
 
}
Time& Time::operator+=(int s)
{
	TotalSecondsw += s;
	normalise();
	return *this;
}	
/*Time Time::operator+(int s)const
{
	return Time(hours,minutes,seconds+s);
}*/
//Time operator+(const Time& t,int s)
//{
	//return Time(t.GetHours(),t.GetMinutes(),t.GetSeconds()+s);
//}
int operator-(const chron::Time& t1,const chron::Time& t2)
{
	return t1.TotalSeconds() - t2.TotalSeconds();
}
std::ostream& operator<<(std::ostream& out,const chron::Time& t)
{
	out<<t.GetHours()<<":"<<t.GetMinutes()<<":"<<t.GetSeconds();
	return out;
}
std::istream& operator>>(std::istream& in,chron::Time& t)
{
	int h,m,s;
	char temp;
	in>>h>>temp;
	in>>m>>temp;
	in>>s>>temp;
	t=Time(h,m,s);
	return in;
}
