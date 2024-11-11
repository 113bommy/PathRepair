n= int(input())
a, dv, dh = [[0, 0]] + [[int(j) for j in input().split()] for i in range(0, n ** 2) ], [False] * (n + 1), [False] * (n + 1)
for i in range(1, n ** 2 + 1):
    if dv[a[i][0]] == dh[a[i][1]] == False:
         dv[a[i][0]] = dh[a[i][0]] = True
         print(f'{i} ', end='')
