#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s -c|-w filename\n", argv[0]);
        return 1;
    }
    char *param = argv[1];
    char *filename = argv[2];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int ch;
    int char_count = 0;
    int word_count = 0;
    int in_word = 0;
    while ((ch = fgetc(fp)) != EOF) {
        char_count++;
        if (ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    // 如果文件最后一个字符不是分隔符，需统计最后一个单词
    if (in_word) word_count++;
    fclose(fp);
    if (strcmp(param, "-c") == 0) {
        printf("字符数：%d\n", char_count);
    } else if (strcmp(param, "-w") == 0) {
        printf("单词数：%d\n", word_count);
    } else {
        printf("Invalid parameter\n");
    }
    return 0;
}
