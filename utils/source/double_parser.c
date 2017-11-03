#include <double_parser.h>
#include <stdio.h>
#include <stdlib.h>

int contains(char ch, const char* arr, int count);
void freeDoubleList(void* elem){

    free(elem);
}

double* toDoubleArray(List* list);

/* Парсит строку согласно заданным разделителям на вещественные числа, 
 * создает массив соответствующего размера и записывает его в arr,
 * а длину массива - в count
 */
int parse(ParseParams params, double** arr, size_t* count){

    List list = createEmptyList(sizeof(double), &freeDoubleList);
    
    const char* string = params.string;

	double val;
	int parsedCount;

	while(*string){

		if(!contains(*string, params.separators, params.sepsCount)){

			int readed = sscanf(string, "%lf", &val);

			push(&list, &val);
            string += readed;

            Node* node = list.head;
        }
        
	    string++;
	}

    *arr = toDoubleArray(&list);
    *count = list.size;

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

double* toDoubleArray(List* list){

    double* arr = (double*)malloc(list->size * sizeof(double));

    int i = 0;

    Node* node = list->head;

    while(node){

        arr[i] = *(double*)(node->val);

        node = node->next;

        i++;
    }
    
    return arr;
}
