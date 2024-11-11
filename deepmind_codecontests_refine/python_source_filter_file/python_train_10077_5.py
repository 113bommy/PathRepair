m,d=map(int,input().split())
ans=0
for i in range(1,m+1):
    for j in range(1,d+1):
        d10=j
        d1=j%10
        if d1>1 and d10>1 and d10*d1==i:
            ans+=1
print(ans)