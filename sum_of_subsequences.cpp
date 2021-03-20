// we are given number as string
// we have to find sum of all contiguous subsequences

#include<bits/stdc++.h>
using namespace std;

int string_to_num(string num){
	int value=0;
	for(char c:num){
		value = 10*value+(c-'0');
	}
	return value;
}

int cal_sum(){
	string num;
	cin>>num;
	int sum=0, max_len = num.size();
	for(int i=0; i<max_len; i++){
		string temp;
		for(int len=1; len<=max_len; len++){
			if(i+len-1 < max_len)
			{
				temp+=num[i+len-1];
				sum+=string_to_num(temp);
			}
		}
		temp.clear();
	}
	return sum;
}

int main(){
	int t;
	t=1;
	while(t--){
		cout<<cal_sum()<<endl;
	}
	return 0;
}