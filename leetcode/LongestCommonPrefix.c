int cmp(const void *a,const void *b) {
    return strcmp(*(char**)a,*(char**)b);
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0) return "";

    qsort(strs,strsSize,sizeof(char*),cmp);

    char *first = strs[0] , *last = strs[strsSize - 1];
    int counter = 0;
    while(first[counter] && first[counter] == last[counter]) counter++;
    char *res = (char*)malloc(sizeof(char) * (counter + 1));
    strncpy(res,first,counter);
    res[counter] = '\0';

    return res;
}
