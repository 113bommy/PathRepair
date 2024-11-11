n = int(input())
maxn = n+10
dpl , dpr , ans = [0]*maxn , [n+1]*maxn , [0]*maxn
a = [0]
a.extend(list(map(int,input().split())))
a.append(0)

for i in range(1,n+1):
    tmp = i-1
    while(a[tmp] >= a[i]):
        tmp = dpl[tmp]
    dpl[i] = tmp

for i in range(n,0,-1):
    tmp = i+1
    while(a[tmp] >= a[i]):
        tmp = dpr[tmp]
    dpr[i] = tmp
    ans[dpr[i]-dpl[i]-1] = max(ans[dpr[i]-dpl[i]-1],a[i])

for i in range(n,0,-1):
    ans[i] = max(ans[i+1],ans[i])

print(' '.join(map(str,ans[1:n]))) 
