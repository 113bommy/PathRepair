import io
import os
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

import math

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = [0] * n
    for i in range(2, n):
        b[i] = 1 if a[i] == a[i-1] + a[i-2] else 0

    _max = 0
    _curr = 0
    pos = 0
    while pos < n:
        if b[pos] == 1:
            _curr += 1
        else:
            _max = max(_max, _curr)
            _curr = 0
        pos += 1
    _max = max(_max, _curr)
    print(_max+2)


if __name__ == '__main__':
    main()
