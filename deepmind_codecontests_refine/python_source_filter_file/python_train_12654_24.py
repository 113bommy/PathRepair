n = int(input())
a = []
i,j = 0,0
for k in range(n):
    a.append([int(s) for s in input().split()])
    if 0 in a[-1]: i, j = k, a[-1].index(0)

if n==1:
    print(1)
else:
    x = sum(v for v in a[0 if i else 1]) - sum(v for v in a[i])
    a[i][j] = x
    ss = [sum(a[i]) for i in range(n)]
    ss += [sum(a[i][j] for i in range(n)) for j in range(n)]
    ss += [sum(a[i][i] for i in range(n))]
    ss += [sum(a[n-i-1][i] for i in range(n))]
    
    print(x if len(set(ss)) == 1 else -1)
