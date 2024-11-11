n, m = [int(x) for x in input().split()]
f = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
for i in range(n):
    f[i] = [f[i], i]
for i in range(m):
    b[i] = [b[i], i]
f.sort()
b.sort()
ans = [0] * m
j = 0
i = 0
flag = 0
while i < m and j < n:
    if b[i][0] < f[j][0]:
        flag = 1
        print('Impossible')
        break
    elif b[i][0] == f[j][0]:
        ans[b[i][1]] = f[j][1] + 1
        i += 1
        if j < n - 1 and f[j + 1][0] == f[j][0]:
            flag = 2
    else:
        j += 1
if i < m and flag != 1 :
    print('Impossible')
elif flag == 2:
    print('Ambiguity')
elif flag == 0:
    print('Possible')
    print(*ans)