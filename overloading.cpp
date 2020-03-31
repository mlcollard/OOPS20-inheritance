/*
    overloading.cpp

    Demonstration of overloading and how it effects interfaces
*/

#include <stdio.h>
#include <unistd.h>

int library_write_open_fd      (int fd);
int library_write_open_FILE    (FILE* file);
int library_write_open_filename(const char* filename);
int library_write_open_memory  (char** buffer, size_t* size);

int library_write_open(int fd);
int library_write_open(FILE* file);
int library_write_open(const char* filename);
int library_write_open(char** buffer, size_t* size);

int main() {

    {
        int output = STDOUT_FILENO;

        library_write_open_fd(output);
    }

    {
        FILE* output = stdin;

        library_write_open_FILE(output);
    }

    {
        const char* output = "overloading.cpp";

        library_write_open_filename(output);
    }

    {
        char* buffer = nullptr;
        size_t size = 0;
        
        library_write_open_memory(&buffer, &size);
    }

    {
        int output = STDOUT_FILENO;

        library_write_open(output);
    }

    {
        FILE* output = stdin;

        library_write_open(output);
    }

    {
        const char* output = "overloading.cpp";

        library_write_open(output);
    }

    {
        char* buffer = nullptr;
        size_t size = 0;
        
        library_write_open(&buffer, &size);
    }

    return 0;
}
