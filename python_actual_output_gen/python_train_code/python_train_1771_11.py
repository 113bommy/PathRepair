n,m = map(int,input().split())
l = list(map(int, input().split()))
su=0
ans=[]
for  i in range(n):
    su+=l[i]
    if su<=m:
        ans.append(0)
    else:
        r=l[0:i]
        r.sort(reverse=True)
        temp=0
        for j in range(len(r)):
            temp+=r[j]
            if su-temp<=m:
                ans.append(j+1)
                break
print(ans)