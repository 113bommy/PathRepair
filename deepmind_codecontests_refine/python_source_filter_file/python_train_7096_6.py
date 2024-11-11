n, m = map(int, input().split())
a = (n - 1) * [-1]
zeros = []
flag = 0
for i in range(m):
    x = list(map(int, input().split()))
    if x[1] == 1:
        if x[0] == 1:
            flag = 1
    if x[0] == 0:
        zeros.append(x)
    else:
        for j in range(x[1], x[2]):
            a[j - 1] = 1
for l in range(len(zeros)):
    for p in range(zeros[l][1], zeros[l][2]):
        if a[p - 1] == -1 or a[p - 1] == 0:
            a[p - 1] = 0
            break
        elif p == zeros[l][2] - 1:
            print('NO')
            exit()
print('YES')
for k in range(n - 1):
    if k == 0 and a[k] == 0:
        a[k] = 50
    elif a[k] == -1:
        a[k] = 20
    elif a[k] == 0:
        a[k] = a[k - 1] - 1
    elif a[k] == 1:
        a[k] = a[k - 1] + 10
if flag == 0:
    print(a[0] + 1, *a)
else:
    print(a[0] - 1, *a)
