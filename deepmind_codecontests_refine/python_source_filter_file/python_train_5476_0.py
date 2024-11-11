n, m = map(int, input().split())
l = list(map(int, input().split()))
a = [-1] * n
s = set(range(1, n + 1))
d = set()
for i in range(m - 1):
    for j in range(1, n + 1):
        if (l[i] + j - l[i + 1]) % n == 0:
            if j in d and a[l[i] - 1] == -1:
                print(-1)
                exit()
            a[l[i] - 1] = j
            d.add(j)
            break
b = list(s - s.intersection(d))
k = 0
for i in range(n):
    if a[i] == -1:
        if k == len(b):
            print(-1)
            exit()
        a[i] = b[k]
        k += 1
print(*a)
