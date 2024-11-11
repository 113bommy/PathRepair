import bisect

n, m, k = map(int, input().split(' '))
x, s = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
c = list(map(int, input().split(' ')))
d = list(map(int, input().split(' ')))
a.append(x)
a.append(0)
ans = n * x
for i in range(m):
    if b[i] <= s:
        j = bisect.bisect_right(d, s - b[i])
        if j > 0:
            j -= 1
            ans = min(ans, (n-c[j])*a[i])
        else:
            ans = min(ans, n*a[i])
print(ans)