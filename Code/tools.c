#include "tools.h"
int my_is_error;

int semantic_error_num = 0;
int semantic_error_type[1000];
int semantic_error_line[1000];
void summit_semantic_error()
{
    for (int i = 0; i < semantic_error_num; i++)
    {
        for (int j = i + 1; j < semantic_error_num; j++)
        {
            if (semantic_error_line[i] > semantic_error_line[j])
            {
                int temp = semantic_error_line[i];
                semantic_error_line[i] = semantic_error_line[j];
                semantic_error_line[j] = temp;
                temp = semantic_error_type[i];
                semantic_error_type[i] = semantic_error_type[j];
                semantic_error_type[j] = temp;
            }
        }
    }
    for (int i = 0; i < semantic_error_num; i++)
    {
        printf("Error type %d at Line %d: testtest.\n", semantic_error_type[i], semantic_error_line[i]);
    }
}
void add_semantic_error(int error_type, int line)
{
    assert(semantic_error_num < 1000);
    semantic_error_type[semantic_error_num] = error_type;
    semantic_error_line[semantic_error_num] = line;
    semantic_error_num++;
}