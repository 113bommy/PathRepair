from math import *


def main():
    y, k, n = map(int, input().split())
    z = k - y % k
    if y + z >= n:
        print(-1)
        return
    arr = []
    x = k - y % k
    while x + y <= n:
        arr.append(x)
        x += k
    print(' '.join(map(str, arr)))

if __name__ == '__main__':
    main()