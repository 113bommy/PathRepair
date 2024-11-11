n = int(input())
x = list(map(int, input()))
a, b = [], []
for i in range(n):
    a.append(x[i])
    b.append(x[n + i])
a.sort()
b.sort()
if a[0] == b[0]:
    print('NO')
else:
    if a[0] > b[0]:
        for j in range(n):
            if a[i] <= b[i]:
                print('NO')
                break
            if j == n - 1:
                print('YES')
    else:
        for j in range(n):
            if a[i] >= b[i]:
                print('NO')
                break
            if j == n - 1:
                print('YES')
