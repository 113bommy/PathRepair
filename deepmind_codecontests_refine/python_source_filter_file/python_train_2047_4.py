n, m, k = map(int, input().split())
if k == n * m:
    print(1, 1)
    exit()
if k < n:
    print(1 + k, 1)
    exit()
k -= n
t = k // (m - 1)
p = k % (m - 1)
x = n - t
if t % 2 == 0:
    y = 1 + p
else:
    y = m - p
print(x, y)
    
