#include <file.h>

#define LINEBUF_LEN 4048

FILE *fp = NULL;

void file_open(char *filename){
    fp = fopen(filename, "a+");

    if(!fp){
        printf("Could not append file!\n");
        exit(EXIT_FAILURE);
    }
}

void file_get_text(char *filename){
    static struct termios newt;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;

    newt.c_lflag &= ~(ICANON);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    file_redraw();

    char ch = '\0';

    char buf[LINEBUF_LEN];

    bzero(buf, LINEBUF_LEN);

    rewind(fp);
    int offset = 0;
    for(offset = 0; (buf[offset] = fgetc(fp)) != EOF; offset++);

    for(int i = offset; (ch = getchar()) != KEY_ESC; i++){
        if(ch == '\\'){
            file_save(filename, buf);
            file_redraw();
            i--;
            continue;
        }
        else if(ch == KEY_BACKSPACE){
            buf[i--] = ' ';
            file_redraw();
        }

        buf[i] = ch;
    }

    file_exit();
}

void file_redraw(){
    char linebuf[LINEBUF_LEN];
    int lineNumber = 0;

    printf(CLEAR);

    rewind(fp);

    printf("--Press [ESC] to quit--\n"
           "--Press [\\] to save--\n\n");

    for(lineNumber = 0; fgets(linebuf, LINEBUF_LEN, fp) != NULL; lineNumber++){
        printf("%s", linebuf);
    }
}

void file_save(char *filename, char *buf){
    fclose(fp);
    remove(filename);
    file_open(filename);
    fputs(buf, fp);
}

void file_exit(){
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    fclose(fp);

    exit(EXIT_SUCCESS);
}