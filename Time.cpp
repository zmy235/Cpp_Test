#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
	double Hi,Mi,Si,Ang;
	double TimeOut;//到达时间
	int Ho,Mo,So;

	while(~scanf("%lf:%lf:%lf",&Hi,&Mi,&Si))
	{
		scanf("%lf",&Ang);
		double TimeIn=Hi+Mi/60+Si/3600;//出发时间
		double degreeIn = (Mi*6+Si*0.1)-(Hi*30+Mi/12+Si/21600);//分针比时针多少度

		if(degreeIn>180) degreeIn=degreeIn-360;
		if(degreeIn<-180) degreeIn=degreeIn+360;

		if(degreeIn>0&&degreeIn<Ang)
		{
			TimeOut=TimeIn+(Ang-degreeIn)*1.0/330;
		}
		else if(degreeIn>Ang)
		{
			TimeOut=TimeIn+(degreeIn+Ang)*1.0/330;
		}
		else if(degreeIn<0&&degreeIn+Ang>0)
		{
			TimeOut=TimeIn+(360+degreeIn-Ang)*1.0/330;
		}
		else if(degreeIn+Ang<0)
		{

		}

		Ho=(int)TimeOut%12;
		Mo=(int)((TimeOut-(int)TimeOut)*60);
		So=(int)(TimeOut*3600-Ho*3600-Mo*60);
		printf("%02d:%02d:%02d\n",Ho,Mo,So);//0:59:59

		fflush(stdin);
	}
}
