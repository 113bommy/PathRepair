n,m,k = map(int,input().split())
x,s = map(int,input().split())
ma = [int(x) for x in input().split()]
mb = [int(y) for y in input().split()]
ms = [[ma[i],mb[i]] for i in range(m)]
kc = [int(x) for x in input().split()]
kd = [int(x) for x in input().split()]
a = 1
n0 = n
for j in range(k):
    if kd[k-1-j] <= s:
        n = n - kc[k-1-j]
        break
if n <= 0:
    t = 0
    a = 0
else:
    t = x*n
if a:
    ms.sort(key=lambda a:a[1])
    b = 1
    j = k - 1
    c = 1
    for i in range(m):
        if b:
            if ms[i][1] <= s:
                sr = s - ms[i][1]
                t = min(t,ms[i][0]*n0)
                if c:
                    while j!=-1 and kd[j]>sr:
                        j -= 1
                    if j == -1:
                        c = 0
                    else:
                        nr = n0 - kc[k-1-j]
                        if nr <= 0:
                            t = 0
                            b = 0
                        else:
                            t = min(t,ms[i][0]*nr)
            else:
                break
print(t)