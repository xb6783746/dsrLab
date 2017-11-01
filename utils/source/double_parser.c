#include <double_parser.h>
#include <stdio.h>

int contains(char ch, const char* arr, int count);

int parse(ParseParams params, List* list){
    
    const char* string = params.string;

	double val;
	int parsedCount;

	while(*string){

		if(!contains(*string, params.separators, params.sepsCount)){

			int readed = sscanf(string, "%lf", &val);

			push(list, val);
            string += readed;

            Node* node = list->head;
        }
        
	    string++;
	}

	return 0;
}

int contains(char ch, const char* arr, int count){
    
    int result = 0;

	for(int i = 0; i < count; i++){
	
		if(ch == arr[i]){

			result = 1;
			break;
		}
	}

	return result;
}
