#include <stdio.h>



int main(int argc, char const *argv[])
{
    if (argc != 2) {
        puts("Invalid args");
        puts("./export.exe shaderFile");
        return 1;
    }
    
    FILE* f = fopen(argv[1], "r");

    if (f == NULL) {
        puts("File does not exist");
        return 2;
    }

    FILE* output = fopen("output.txt", "w");
    
    char* startString = "[{\"data\":[{\"type\":1,\"properties\":{\"name\":\"Shader\",\"enabled\":{\"animated\":false,\"keyframes\":[{\"value\":1,\"frame\":0,\"tween\":0,\"controlPoints\":[[-10,0],[10,0]]}]},\"fragShader\":";
    //TODO: implement customProperties
    char* endString = "},\"customProperties\":[]}],\"baseType\":\"effect\",\"assets\":[]}]";

    fputs(startString, output);
    fputc('"', output);
    //TODO: replace /n char with /n string
    int c = fgetc(f);
    while (c != EOF) {
        if (c == '\n') {
            fputs("\\n", output);
        } else {
            fputc(c, output);
        }
        c = fgetc(f);
    }

    fputc('"', output);
    fputs(endString, output);

    fclose(output);
    fclose(f);



    puts("all good");
    
    
    return 0;
}
