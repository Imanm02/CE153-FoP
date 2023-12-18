#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum Types {Int, Float, Char, Bool};
long unsigned int* typeSize;
char** typename;

void* arr;
int* start;
enum Types* type;
int size;

void add_int(int val){
	if(size==0){
		arr = malloc(*(typeSize+Int));
		start = malloc(sizeof(int));
		type = malloc(sizeof(enum Types));
		*((int*)arr) = val;
		*(start) = 0;
		*(type) = Int;
	}
	else{
		int st = *(start+size-1) + *(typeSize+ *(type+size-1));
		arr = realloc(arr,st + *(typeSize+Int));
		start = realloc(start,(size+1)*sizeof(int));
		type = realloc(type,(size+1)*sizeof(enum Types));
		*((int*)(arr+st)) = val;
		*(start+size) = st;
		*(type+size) = Int;
	}
	printf("%s %d added to index %d\n",*(typename+Int),val,size);
	size++;
	return;
}
void add_float(double val){
	if(size==0){
		arr = malloc(*(typeSize+Float));
		start = malloc(sizeof(int));
		type = malloc(sizeof(enum Types));
		*((double*)arr) = val;
		*(start) = 0;
		*(type) = Float;
	}
	else{
		int st = *(start+size-1) + *(typeSize+ *(type+size-1));
		arr = realloc(arr,st + *(typeSize+Float));
		start = realloc(start,(size+1)*sizeof(int));
		type = realloc(type,(size+1)*sizeof(enum Types));
		*((double*)(arr+st)) = val;
		*(start+size) = st;
		*(type+size) = Float;
	}
	printf("%s %.6lf added to index %d\n",*(typename+Float),val,size);
	size++;
	return;
}
void add_char(char val){
	if(size==0){
		arr = malloc(*(typeSize+Char));
		start = malloc(sizeof(int));
		type = malloc(sizeof(enum Types));
		*((char*)arr) = val;
		*(start) = 0;
		*(type) = Char;
	}
	else{
		int st = *(start+size-1) + *(typeSize+ *(type+size-1));
		arr = realloc(arr,st + *(typeSize+Char));
		start = realloc(start,(size+1)*sizeof(int));
		type = realloc(type,(size+1)*sizeof(enum Types));
		*((char*)(arr+st)) = val;
		*(start+size) = st;
		*(type+size) = Char;
	}
	printf("%s %c added to index %d\n",*(typename+Char),val,size);
	size++;
	return;
}
void add_bool(short int val){
	if(size==0){
		arr = malloc(*(typeSize+Bool));
		start = malloc(sizeof(int));
		type = malloc(sizeof(enum Types));
		*((short int*)arr) = val;
		*(start) = 0;
		*(type) = Bool;
	}
	else{
		int st = *(start+size-1) + *(typeSize+ *(type+size-1));
		arr = realloc(arr,st + *(typeSize+Bool));
		start = realloc(start,(size+1)*sizeof(int));
		type = realloc(type,(size+1)*sizeof(enum Types));
		*((short*)(arr+st)) = val;
		*(start+size) = st;
		*(type+size) = Bool;
	}
	printf("%s %s added to index %d\n",*(typename+Bool),(val?"True":"False"),size);
	size++;
	return;
}

int read_int(int i){
	int st = *(start+i);
	return *((int*)(arr+st));
}

double read_float(int i){
	int st = *(start+i);
	return *((double*)(arr+st));
}

char read_char(int i){
	int st = *(start+i);
	return *((char*)(arr+st));
}

short int read_bool(int i){
	int st = *(start+i);
	return *((short int*)(arr+st));
}

void access(int i){
	if(i<0 || i>=size){
		printf("Out of Boundaries\n");
		return;
	}
	enum Types t = *(type + i);
	switch (t)
	{
	case Int:
		printf("%s %d is in index %d\n",*(typename+Int),read_int(i),i);
		break;
	case Float:
		printf("%s %0.6lf is in index %d\n",*(typename+Float),read_float(i),i);
		break;
	case Char:
		printf("%s %c is in index %d\n",*(typename+Char),read_char(i),i);
		break;
	case Bool:
		printf("%s %s is in index %d\n",*(typename+Bool),(read_bool(i)?"True":"False"),i);
		break;
	}
}

void print_all(){
	if(size==0){
		printf("Nothing Exists...\n");
		return;
	}
	for(int i=0;i<size;i++){
		enum Types t = *(type+i);
		switch (t)
		{
		case Int:
			printf("%d: %s - %d\n",i,*(typename+Int),read_int(i));
			break;
		case Float:
			printf("%d: %s - %0.6lf\n",i,*(typename+Float),read_float(i));
			break;
		case Char:
			printf("%d: %s - %c\n",i,*(typename+Char),read_char(i));
			break;
		case Bool:
			printf("%d: %s - %s\n",i,*(typename+Bool),read_bool(i)?"True":"False");
			break;
		}
	}
}

void erase_all(){
	free(arr);
	free(start);
	free(type);
	size = 0;
	printf("All Data Has Been Cleared...\n");
}

int main(){
	typeSize = malloc(4*sizeof(const long unsigned int));
	*(typeSize+Int) = sizeof(int);
	*(typeSize+Float) = sizeof(double);
	*(typeSize+Char) = sizeof(char);
	*(typeSize+Bool) = sizeof(short int);
	typename = malloc(4*sizeof(char*));
	*(typename+Int) = "Integer";
	*(typename+Float) = "Float";
	*(typename+Char) = "Character";
	*(typename+Bool) = "Boolean";
	size = 0;
	char *command = malloc(20);
	while(1){
		scanf(" %s",command);
		if(*command=='i'){
			int val;
			scanf("%d",&val);
			add_int(val);
		}
		else if(*command=='f'){
			double val;
			scanf("%lf",&val);
			add_float(val);
		}
		else if(*command=='c'){
			char val;
			scanf(" %c",&val);
			add_char(val);
		}
		else if(*command=='b'){
			short int val;
			scanf("%hd",&val);
			add_bool(val);
		}
		else if(*command=='a'){
			int val;
			scanf("%d",&val);
			access(val);
		}
		else if(*command=='p'){
			//scanf("%*s");
			print_all();
		}
		else if(*command=='e'){
			//scanf("%*s");
			erase_all();
		}
		else if(*command=='o'){
			break;
		}
		else{
			break;
		}
	}
	return 0;
}