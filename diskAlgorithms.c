#include <stdio.h>
#include <stdlib.h>

#define CYLINDERS 5000
#define REQUESTS 1
#define ARRAYSIZE 10

int arr[6][REQUESTS];

int determineAlgorithm(int * ranArray, int ranAlgorithm);
int fcfs(int * ranArray);
int sstf(int * ranArray);
int start = 5;
int ranArray[ARRAYSIZE];


int main (void) {

	int i, j;
	int requestCount = 0;
		
	for(i = 0; i < ARRAYSIZE; i++) {
		ranArray[i] = 0;
	}

	for(i = 0; i < ARRAYSIZE; i++) {
		int ran = rand() % 5000;
		ranArray[i] = ran;
		printf("%d\n",ranArray[i]);
		if(i == 5) {
			printf("START: %d\n",ranArray[i]);
		}
	}

	for(i = 0; i < 6; i++) {
		for(j = 0; j < REQUESTS; j++) {
			arr[i][j] = 0;
		}
	}

	while(requestCount < REQUESTS) {

		//int ranAlgorithm = rand() % 6;
		int ranAlgorithm = 0;
		int headMovement = determineAlgorithm(ranArray, ranAlgorithm);
		arr[ranAlgorithm][requestCount] = headMovement;
		printf("Head Movement: %d\n",arr[ranAlgorithm][0]);
		requestCount++;
	}
	for(i = 0; i < 6; i++) {
		for(j = 0; j < REQUESTS; j++) {
			printf("huh: %d\n",arr[i][j]);
		}
	}
	
	return 0;
}

int determineAlgorithm(int * ranArray, int ranAlgorithm) {
	int headCount;
	if(ranAlgorithm == 0) {
		printf("HUHHHHH\n");
		headCount = fcfs(ranArray);
	}
	else if(ranAlgorithm == 1) {
		printf("INSIDE\n");
		headCount = sstf(ranArray);
		printf("FINAL %d\n",headCount);
	}
	return headCount;
}

int fcfs(int * ranArray) {

	int i;
	int head_movement;
    for(i=start; i < 10; i++) {
    	if(i+1 < 10) {
    		if(ranArray[i+1] > ranArray[i]) {
	    		int num = ranArray[i+1] - ranArray[i];
	    		//printf("num: %d\n",num);
	    		head_movement = head_movement+ num;
	    		printf("Head1: %d\n",head_movement);
    		}
    		else {
    			int num = ranArray[i] - ranArray[i+1];
	    		//printf("num: %d\n",num);
	    		head_movement = head_movement+ num;
	    		printf("Head1: %d\n",head_movement);
    		}
    	}
    	else {
    		break;
    	}
    }
    for(i=0; i < start; i++) {
    	if(i == 0) {
    		//printf("I: %d\n",i);
    		if(ranArray[9] > ranArray[0]) {
	    		int num2 = ranArray[9] - ranArray[0];
	    		//printf("num2: %d\n",num2);
	    		head_movement = head_movement + num2;
	    		printf("Head2: %d\n",head_movement);
    		}
    		else {
    			int num2 = ranArray[0] - ranArray[9];
	    		//printf("num2: %d\n",num2);
	    		head_movement = head_movement + num2;
	    		printf("Head2: %d\n",head_movement);
    		}
    	}
    	else {
    		//printf("I: %d\n",i);
    		if(ranArray[i] > ranArray[i-1]) {
    			int num3 = ranArray[i] - ranArray[i-1];
    			//printf("num3: %d\n",num3);
    			head_movement = head_movement+ num3;
    			printf("Head3: %d\n",head_movement);
    		}
    		else {
    			int num3 = ranArray[i-1] - ranArray[i];
    			//printf("num3: %d\n",num3);
    			head_movement = head_movement+ num3;
    			printf("Head3: %d\n",head_movement);
    		}
    	}
    }
        
    return head_movement;
}


int sstf(int * ranArray) {

	int shortest = 5001;
	int j;
	int hey = 10;
	int newStart = ranArray[start];
	//printf("First: %d\n",newStart);
	int newHead = 0;
	int saveCurrent;
	int arrTest[10];
	int saveLocation;
	int i = 0;
	for(i = 0; i < 10; i++) {
		arrTest[i] = 0;
	}
	arrTest[start]++;

	while(hey > 0) {

		int distance;
		
		for(j = 0; j< ARRAYSIZE; j++) {

			int current = ranArray[j];
			int used = arrTest[j];

			if(used < 1 && newStart > current) {
				distance = newStart - current;
			}
			else if(used < 1 && newStart < current) {
				distance = current - newStart;
			}
			if(used < 1 && distance < shortest) {
				shortest = distance;
				saveCurrent = current;
				saveLocation = j;
			}
		}

		distance = 0;
		arrTest[saveLocation]++;
		int num = arrTest[saveLocation];
		int difference = 0;

		if(num < 2 && saveCurrent < newStart) {
			difference = newStart - saveCurrent;
			newHead += difference;
		}
		else if(num < 2 && saveCurrent > newStart) {
			difference = saveCurrent - newStart;
			newHead += difference;
		}

		printf("NEW HEAD FINAL: %d\n",newHead);
		newStart = saveCurrent;
		saveCurrent = 0;
		shortest = 5001;
		--hey;
	}
	return newHead;
}






