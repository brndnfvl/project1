#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

//folding
int hash_folding(int key){
	int sum = 0;
	while(key > 0){
		int part = key % 100;
		sum += part;
		key /= 100;
	}
	return sum % SIZE;
}

int main(){
	int keys[] = {65,65,74,33,23};
	puts("hash table (handling with linear probing)");
	
	int hasht[SIZE] = {0};
	
	for(int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++){
		int index = hash_folding(keys[i]);
		
		//linear prob
		while(hasht[index] != 0){//kalo udh ada data, move ke next index
			printf("index eror %d\n",index);
			index = (index + 1)  % SIZE; 
		}
		
		printf("key: %d, hash index: %d\n", keys[i], index);
		hasht[index] = keys[i];
	}
	
	for(int i = 0; i < SIZE; i++){
		printf("index[%d] : %d\n", i, hasht[i]);
	}
	return 0;
}
