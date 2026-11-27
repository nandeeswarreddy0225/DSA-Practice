class Solution {

    public int superPow(int a, int[] b) {

        int result = 1;
        a = a % 1337;

        for (int digit : b) {

            result = (pow(result, 10) * pow(a, digit)) % 1337;

        }

        return result;
    }

    public int pow(int a, int b) {

        int result = 1;
        a = a % 1337;

        while (b > 0) {

            if (b % 2 == 1) {
                result = (result * a) % 1337;
            }

            a = (a * a) % 1337;
            b = b / 2;
        }

        return result;
    }
}