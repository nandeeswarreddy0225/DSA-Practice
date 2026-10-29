
int passThePillow(int n, int time) {
    int position = time % (2 * (n - 1));

    if (position < n) {
        return position + 1;
    }

    return 2 * n - 1 - position;
}
