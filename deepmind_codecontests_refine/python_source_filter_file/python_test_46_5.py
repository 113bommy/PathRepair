
import sys
input = sys.stdin.readline

c = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    k = max(a)
    if n==1:
        print(0)
        continue

    i = n
    u = 0
    while True:
        i -= 1
        u += 1
        p = a[i]

        if p == k:
            c.append(u-1)
            break

        while p > a[i-1]:
            i -= 1

print(*c, sep="\n")
