N = int(input())
a = 1
L = list(map(int, input().split()))
for i in L:
    a *= i
    if (a > 1e18):
        break

print(-1 if a > 1e18 else a)
