#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
typedef unsigned short ElemType;

int main(void){
	ifstream infile;
	ofstream outfile;
	vector<ElemType> vec;
	unsigned char tmpData;
	int i=1;
	string inPath,outPath;
	cout<<"input the infile name(txt):";
	cin>>inPath;
	cout<<"input the file name you want to save to:";
	cin>>outPath;
	infile.open(inPath,ios::binary);
	if(!infile){
		cout<<"file open failed!"<<endl;
		exit(-1);
	}
	outfile.open(outPath);
	outfile<<"v2.0 raw"<<endl;
	while(infile>>tmpData){
		unsigned short tmp=(unsigned short)tmpData;
		vec.push_back(tmp);
	}
	for(i=1;i<=vec.size();i++){
		if(i%16==0){
			outfile<<hex<<vec[i-1]<<endl;;
		}else if(i%2==0){
			outfile<<hex<<vec[i-1]<<" ";
		}else{
			outfile<<hex<<vec[i-1];
		}
	}
	outfile<<endl;
	cout<<hex<<10<<"\tjust for hex test"<<endl;
	cout<<"press any key to continue..."<<endl;
	getchar();
	return 0;
}

