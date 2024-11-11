import sys

n, p, k = list(map(int, sys.stdin.readline().strip().split()))
a = list(map(int, sys.stdin.readline().strip().split()))

for i in range (0, n):
    a[i] = (a[i] ** 4 - k * a[i]) % p
    a[i] = a[i] + 2 * p
    a[i] = a[i] % p

a.sort()
c = 1
x = a[0]
ans = 0
for i in range (1, n):
    if a[i] == x:
        c = c + 1
    else:
        ans = ans + (c * (c-1) // 2)
        c = 1
        x = a[i]
ans = ans  + (c * (c-1) // 2)
print(ans)
