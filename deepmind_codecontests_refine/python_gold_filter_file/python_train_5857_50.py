# Author: Uday Gupta
import sys

input = sys.stdin.readline

t = int(input())

for test in range(t):
    n, k = list(map(int, input().split()))

    if n > k:
        x = k
        ans = (x * (x + 1)) // 2

    else:
        x = n - 1
        ans = (x * (x + 1)) // 2
        ans += 1


    print(ans)

    