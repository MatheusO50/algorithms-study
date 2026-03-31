bool isPalindrome(int x) {
    int res = 0 ; 
    int xcopy = x;

    while(x > 0) {
        res = (res * 10) + (x % 10);
        x /= 10;
    }
    return res == xcopy;
}
