#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

int main(void){
	ifstream infile;
	vector<int> q[5];
	int tmp,i;
	ofstream outfile("并行递推结果排序.txt");
	
	infile.open("并行递推结果.txt");
	for(i=0;i<5;i++){
		string str;
		getline(infile,str);
		stringstream ss(str);
		int tmp;
		while(ss>>tmp){
			q[i].push_back(tmp);
		}
	}
	infile.close();
	
	for(i=0;i<5;i++){
		sort(q[i].begin(),q[i].end()); 
		vector<int>::iterator it;
		for(it=q[i].begin();it!=q[i].end();it++){
			outfile<<*it<<" ";
		}
		outfile<<endl<<endl;
	}
	outfile.close();
	
	cout<<"press any key to continue..."<<endl;
	getchar();
}

