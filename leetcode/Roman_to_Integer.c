int romanToInt(char* s) {
    int res = 0;
    int prep = 0;
    char roman[7] = {'I','V','X','L','C','D','M'};
    int val[7] = {1,5,10,50,100,500,1000};

    for(int i = strlen(s) - 1 ; i >= 0 ; i--) {
        for(int j = 0 ; j < 7 ; j++) {
            if(s[i] == roman[j]) {
                if(val[j] < prep) {
                    res -= prep;
                    prep -= val[j];
                    res += prep;
                } else {
                    res += val[j];
                    prep = val[j];
                }
            }
        }
    }
    return res;
}
