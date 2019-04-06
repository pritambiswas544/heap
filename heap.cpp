#include<iostream>
#include<climits>
using namespace std;
					//min binary heap implementation with array
class heap{
	public:
					//pointer to the elements of array
		int * arr;
					//current size
		int csize;
					//max size
		int msize;
					//constructor
heap(int msize){
					//by deafult the current size should point to the last element i.e msize
		arr=new int(msize);
		this->msize=msize;
		csize=0;
	};
					//swapping two elements of the array
	void swap(int *a,int *b){
		int temp=*a;
		*a=*b;
		*b=temp;
	}
					//parent wrt to the current index
	int parent(int i){
		return(i-1)/2;
	}
					//left child
	int left(int i){
		return (i*2)+1;
	}
					//right child
	int right(int i){
		return (i*2)+2;
	}
					//returning the minimum element of the tree
	int getmin(){
		return arr[0];
	}
					//inserting a value
					//1-value to be inserted must be at the bottom
					//2-then compare
	void insert(int value){
					//size overflow
		if(csize==msize){
			cout<<"can't insert any more values: size"<<endl;
			return;
		}
		
					//first insert the new value at the end
			csize++;
					//for the value of the arr index
			int i=csize-1;
			arr[i]=value;
					//checking for binary property
			while(i!=0 and arr[parent(i)]>arr[i]){
				swap(&arr[i],&arr[parent(i)]);
				i=parent(i);
			}
		
	}
					//displaying the array elements
					//level display of heap
	void display(){
		
		for(int a=0;a<csize;a++){
			cout<<arr[a]<<"|";
	}
		cout<<endl;
	}
					//extract the min value from a heap
	int extractmin(){
		int root=getmin();
					

			
					//heap is empty
		if(csize<=0){
			cout<<"error no element to extract"<<endl;
		}
					//for heap with 1 element
		else if(csize==1){
			return arr[0];
		}
					//for other cases
		else
					//copying the last element to the root
			arr[0]=arr[csize-1];
					//decreasing heap size by 1
			csize--;
					//calling minheapify on root
			minheapify(0);
		
			return getmin();
		
	}
					//min heapify
	void minheapify(int i){
					//storing left and right child
		int a=left(i);
		int b=right(i);
		int smallest=i;
					//first deciding the smallest element
		if(a<csize && arr[a]<arr[i])
			smallest=a;
		if(b<csize && arr[b]<arr[smallest])
			smallest=b;	//smallest elelement is decided
					//swapping the eleemnt with the smallest of its subtree
		if(smallest!=i){
			swap(&arr[i],&arr[smallest]);
					//calling minheapify at the swapped element
			minheapify(smallest);
		}
	}
					//reduce the value at i th position with a lesser value
	void decra(int i,int value){
		arr[i]=value;		//assumming replaced value is lesser than the previous value
		while(i!=0 and arr[parent(i)]>arr[i]){
			swap(&arr[i],&arr[parent(i)]);
			i=parent(i);
		}
	}
					//deleting a node at a particular pos
	void deleteat(int i){
					//decreasing the value to INT_MIN
		decra(i,INT_MIN);
					//extracting the minimun i.e. root
		extractmin();
	}
};
	int main(){
    	heap bh1(20);
    	for(int i = 8; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
		cout<<endl;
        bh1.display();
    	}
    	bh1.extractmin();
    	bh1.display();
    	bh1.deleteat(3);
    	bh1.display();
    	cout << endl;
}
				

			
					
