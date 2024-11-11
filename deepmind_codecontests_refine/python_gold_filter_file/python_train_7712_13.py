from sys import stdin
input = stdin.readline
import math

def main():
    n = int(input())
    a = list(map(int, input().split()))

    if n == 1:
        print(0)
    else:
        L = -1
        R = n
        sum1 = 0
        sum3 = 0
        ans = 0
        while L+1 < R:
            L += 1
            sum1 += a[L]
            while R-1 > L and sum3 < sum1:
                R -= 1
                sum3 += a[R]
            if sum3 == sum1:
               ans = max(ans, sum1)

        print(ans)


if __name__ == '__main__':
    main()