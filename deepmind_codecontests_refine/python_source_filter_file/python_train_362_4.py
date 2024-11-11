n , m = map(int, input().split())
a = list(map(int, input().split()))

d = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
for i in range(n):
    d[a[i] - 1] +=  1
res = 0
for i in range(n):
    res += n - d[a[i] - 1]
res /= 2
print(res)