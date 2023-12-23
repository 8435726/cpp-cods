#include <iostream>
//Write a program to reverse an array or string
void revereseArray (int array[],int start,int end){
	while(start<end){
		int temp=array[start];
		array[start]=array[end];
		start=temp;
		start++;
		end--;
	}
void printArray(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
		cout<<endln;
	}	
}
}
int main(int argc, char** argv) {
	int arr[]={1,2,3,4,5};
	int n= sizeof(arr);
	revereseArray(arr,0,n-1);
	print(arr,n);
	
	return 0;
}
