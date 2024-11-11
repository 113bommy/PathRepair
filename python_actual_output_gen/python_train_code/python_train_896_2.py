n,w = map(int,input().split())
l = list(map(int,input().split()))
ans = []
for i in range(n):
    ans.append(l[i]//2+l[i]%2)
    w-=l[i]//2+l[i]%2
    l[i] = (l[i],i)
if w <0:
    print(-1)
else:
    l = list(reversed(list(sorted(l))))
    for i in range(n):
        w,ans[l[i][1]] = max(0,ans[l[i][1]]-l[i][0]),min(l[i][0],ans[l[i][1]]+w)
        if(w==0):
            break
    for i in range(n):
        print(ans[i],end = " ")