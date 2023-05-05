#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {
    unsigned int length=0;

    FILE *file;
    file = fopen(path, "r");

    while (!feof(file) && length<=max_size) {
        fscanf(file, "%u -> *%c* \n", &indexes[length], &letters[length]);
        length++;
    }
    
    fclose(file);

    return length;
}

void sort_array (unsigned int indexes[], char letters[], unsigned int length, char sorted[]){
    unsigned int j;
    for (size_t i = 0; i < length; i++)
    {
        j=0;
        while (i!=indexes[j] && j<length)
        {
            j++;
        }
        sorted[i]=letters[j];
    }
    
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    filepath = parse_filepath(argc, argv);

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    length=data_from_file(filepath, indexes, letters, MAX_SIZE);

    sort_array(indexes,letters,length,sorted);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

