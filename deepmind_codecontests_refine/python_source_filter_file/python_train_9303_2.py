n, m, k = list(map(int, input().split()))
a = sorted(list(map(int, input().split())), reverse=True)
c = 0
while k < m and c < n:
    k += a[c] - 1

    c += 1
if c > 0 and k >= m:
    print(c)
else:
    print(-1)
