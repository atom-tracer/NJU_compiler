#include <time.h>
#include <config.h>
#include <IR_parse.h>
#include <IR_optimize.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input.ir output.ir\n", argv[0]);
        return 1;
    }
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    srand((unsigned int)time(NULL));
    IR_parse(input_file);
    IR_optimize();
    IR_output(output_file);
    if (ir_program_global != NULL) {
        RDELETE(IR_program, ir_program_global);
    }

    return 0;
}
