def check(o, z, ans):
    for i in o:
        for j in range(i[0]+1, i[1]+1):
            if ans[j] < ans[j - 1]:
                return 0
    for i in z:
        f = -1
        for j in range(i[0]+1, i[1]+1):
            f=0
            if ans[j] < ans[j - 1]:
                f = 1
                break
        if f == 0:
            return 0
    return 1


n, m = map(int, input().split())
a = []
z = []
o = []
for i in range(m):
    t, l, r = map(int, input().split())
    if t:
        o.append([l, r])
    else:
        z.append([l, r])
o.sort()
z.sort()
ans = [-1 for i in range(n+1)]
for i in o:
    for j in range(i[0]+1, i[1]+1):
        ans[j]=0
ans[0]=100000
for i in range(1,n+1):
    ans[i]+=ans[i-1]
if check(o, z, ans):
    print('YES')
    for i in range(1, n+1):
        print(ans[i], end=' ')
    print('')
else:
    print('NO')
