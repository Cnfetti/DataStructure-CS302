
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	printf("%d and %d were swapped!\n",*x,*y);
}

void printArr(int *arr, int size){
	int i;
	printf("\n");
	for(i=0;i<size;i++) printf("%d ",arr[i]);
	printf("\n\n");
}

//---------------------------------------------------------------BUBBLE SORT--------------------------------------------------------------

void bubbleSort(int *arr, int size){
	int flag,i,j;
	for(flag=1,i=1; i<size && flag==1; i++){
		printf("\nFlag is 1. If flag is 0 loop stops.\n");
		for(flag=0,j=0; j<size-i; j++){
			printf("Pass %d: Comparing arr[%d] with all elements from arr[%d] to arr[%d] & placing in proper position..\n",i,j,j+1,size-1);
			printf("Flag is 0\n");
			if(arr[j]>arr[j+1]){
				printf("Flag is made to 1 as %d is greater than %d, and also ",arr[j],arr[j+1]);
				swap(&arr[j],&arr[j+1]);
				printArr(arr,size);
				flag = 1;
			}
		}
	}
}


//-----------------------------------------------------------LINEAR INSERTION SORT---------------------------------------------------------

void linInsSort(int *arr, int size){
	int i,j,temp;
	for(i=1;i<size;i++){
		for(temp=arr[i],j=i-1; j>=0 && temp<arr[j]; j--){
			printf("temp = %d < arr[%d] = %d found!\nShifting...", temp, j, arr[j]);
			arr[j+1] = arr[j];
			printArr(arr,size);
		}
		arr[j+1] = temp;
		printArr(arr,size);
	}
}

//-----------------------------------------------------------BINARY INSERTION SORT---------------------------------------------------------

int binSearch(int *arr, int key, int lb, int ub) {
	int mid;
	if(lb<=ub) {
		mid=(lb+ub)/2;
		if (key==arr[mid]) return mid;
		else if (key<arr[mid]) return binSearch(arr,key,lb,mid-1);
		else if (key>arr[mid]) return binSearch(arr,key,mid+1,ub);
	}
	else return ub;
}

void binInsSort(int *arr, int size){
	int i,j,temp,pos;
	for(i=1;i<size;i++){
		pos = binSearch(arr,arr[i],0,i-1);
		for(temp=arr[i], j=i-1; j>pos; j--){
			arr[j+1] = arr[j];
			arr[j+1] = temp;
			printArr(arr,size);
		}
		printArr(arr,size);
	}
}


//-----------------------------------------------------------SELECTION SORT----------------------------------------------------------------

void selectionSort(int *arr, int size){
	int i,j,p;
	for(i=0;i<size-1;i++){
		for(j=i+1,p=i; j<size; j++){
			if(arr[p]>arr[j]){
				p=j;
			}
		}
		if(p!=i){
			swap(&arr[p],&arr[i]);
		}
		printArr(arr,size);
	}
}


//-------------------------------------------------------------SHELL SORT------------------------------------------------------------------

void shellSort(int *arr, int size){
	int i,j,temp,gap = size/2;
	while(gap>0){
		for(i=gap; i<size; i++){
			for(temp=arr[i],j=i-gap; j>=0 && temp<arr[j]; j=j-gap){
				arr[j+gap] = arr[j];
				printArr(arr,size);
			}
			arr[j+gap] = temp;
			printArr(arr,size);
		}
		gap = gap/2;
	}
	printArr(arr,size);
}


//---------------------------------------------------------------MERGE SORT----------------------------------------------------------------

void mergeSort(int *arr, int lb, int ub){
	int i, j, k, arr2[ub];
	if(lb<ub){
		int mid = (lb+ub)/2;
		mergeSort(arr,lb,mid);
		mergeSort(arr,mid+1,ub);
		for(i=lb, j=mid+1, k=lb; i<=mid && j<=ub; ){
			if(arr[i]<arr[j]){
				arr2[k]=arr[i];
				k++; i++;
			}
			else{
				arr2[k]=arr[j];	
				k++; j++;
			}
		}
		while(i<=mid){
			arr2[k++]=arr[i++];
		}
		while(j<=ub){
			arr2[k++]=arr[j++];
		}
		for(k=lb; k<=ub; k++){
			arr[k] = arr2[k];
		}
		printArr(arr,ub+1);
	}
}	
		

//---------------------------------------------------------------QUICK SORT----------------------------------------------------------------

void quickSort(int *arr, int lb, int ub, int size){
	int pivot = arr[lb];
	int i,up = ub;
	int down = lb;
	while(down<up){
		while(pivot<arr[up]) up--;
		while(pivot>=arr[down] && down<ub) down++;
		if(down<up){
			swap(&arr[down],&arr[up]);
			printArr(arr,size);
		}
	}
	swap(&arr[lb],&arr[up]);
	printArr(arr,size);
	if(lb<up-1) quickSort(arr,lb,up-1,size);
	if(up+1<ub) quickSort(arr,up+1,ub,size);
}


//---------------------------------------------------------------RADIX SORT----------------------------------------------------------------

int getMax(int arr[], int n){
    int i;
    int max = arr[0];
    for (i=1; i<n; i++){
        if (arr[i]>max) max = arr[i];
    }
    return max;
}

void radixSort(int arr[], int n){
	int i,digitPlace = 1;
	int result[n];
	int largestNum = getMax(arr,n);
	while(largestNum/digitPlace >0){
		int count[10] = {0};
		for (i=0; i<n; i++)
			count[(arr[i]/digitPlace)%10]++;
		for (i=1; i<10; i++)
			count[i] += count[i-1];
		for (i=n-1; i>= 0; i--){
			result[count[(arr[i]/digitPlace)%10]-1] = arr[i];
			count[(arr[i]/digitPlace)%10]--;
		}
		for (i=0; i<n; i++)
			arr[i] = result[i];
		digitPlace *= 10;
	}
}
/*

*/

//----------------------------------------------------------------------------------------------------------------------------------------

int main() {
	int siz,i,data;
	printf("Number of elements in array?: ");
	scanf("%d",&siz);
	int *array = (int *)malloc(siz*sizeof(int));
	for(i=0;i<siz;i++){
		printf("Enter element %d of array: ",i+1);
		scanf("%d",&array[i]);
	}
	while(1) {
		printf("\n===============================================================================\n");
		printf("MENU:\n");
		printf("  1.BUBBLE SORT\n");
		printf("  2.LINEAR INSERTION SORT\n");
		printf("  3.BINARY INSERTION SORT\n");
		printf("  4.SELECTION SORT\n");
		printf("  5.SHELL SORT\n");
		printf("  6.MERGE SORT\n");
		printf("  7.QUICK SORT\n");
		printf("  8.RADIX SORT\n");
		printf("  0.EXIT\n");
		printf("Your array: \n");
		printArr(array,siz);
		printf("Enter your choice: \n");
		int user_ch;
		scanf("%d", &user_ch);
		switch(user_ch) {
			case 1: bubbleSort(array,siz);
			break;
			case 2: linInsSort(array,siz);
			break;
			case 3: binInsSort(array,siz);
			break;
			case 4: selectionSort(array,siz);
			break;
			case 5: shellSort(array,siz);
			break;
			case 6: mergeSort(array,0,siz-1);
			break;
			case 7: quickSort(array,0,siz-1,siz);
			break;
			case 8: radixSort(array,siz);
			break;
			case 0: return 0;
			default: printf("Invalid! Choose again");
		}
	}
}
