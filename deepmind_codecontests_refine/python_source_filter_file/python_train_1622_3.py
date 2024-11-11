import sys


def main():
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    if s != 0:
        print('YES')
        print(1)
        print(1, n)
    else:
        s_left = 0
        for i in range(n):
            s_left += a[i]
            s -= a[i]
            if s_left != 0 and s != 0:
                print('YES')
                print(2)
                print(1, i + 1)
                print(i + 1, n)
                break
        else:
            print('NO')


main()