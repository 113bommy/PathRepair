v = int(input())
a = list(map(int, input().split()))
m = min(a)
n = v // m
if n == 0:
    print(-1)
    exit()
for i in range(9):
    if a[i] == m:
        d = i + 1
res = [d] * n
v -= n * m
for i in range(n):
    temp = -1
    for j in range(d, 9):
        if a[j] <= v + m:
            temp = j
    if temp != -1:
        res[i] = temp + 1
        v -= a[temp] - m
print(''.join(map(str, res)))
