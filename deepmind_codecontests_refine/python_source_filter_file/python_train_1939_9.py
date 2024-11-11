n = int(input())
n *= 2
a = [int(i) for i in input().split()]
a.sort()
ans = 100000000
for i in range(n):
    for j in range(i + 1, n):
        b = a[:i] + a[i+1:j] + a[j + 1:]
        cr = 0
        for k in range(1, n - 2):
            cr += b[k] - b[k - 1]
        ans = min(ans, cr)
print(ans)
