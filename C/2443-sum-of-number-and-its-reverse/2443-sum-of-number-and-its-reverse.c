
bool sumOfNumberAndReverse(int num) {
    for (int x = 0; x <= num; x++) {
        int temp = x;
        int rev = 0;

        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        if (x + rev == num) {
            return true;
        }
    }

    return false;
}
