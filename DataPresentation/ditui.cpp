#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int main(void){
	fstream file;
	string qS[6];
	qS[0]="21";
	int xIn=20,i;
	while(xIn>0){
		qS[5]=qS[4];qS[4]=qS[3];qS[3]=qS[2];
		qS[2]=qS[1]+" "+qS[5];
		qS[1]=qS[0];
		qS[0]=qS[5]+" "+to_string(xIn);
		cout<<"qS[0]\t"<<qS[0]<<endl
			<<"qS[1]:\t"<<qS[1]<<endl
			<<"qS[2]:\t"<<qS[2]<<endl
			<<"qS[3]:\t"<<qS[3]<<endl
			<<"qS[4]:\t"<<qS[4]<<endl
			<<"qS[5]:\t"<<qS[5]<<endl<<endl;
			xIn--;
	}
	
	file.open("并行递推结果.txt",ios::out);
	for(i=0;i<6;i++){
		file<<qS[i]<<endl;
	}	
	cout<<"press any key to continue..."<<endl;
	getchar();
	return 0;
}
