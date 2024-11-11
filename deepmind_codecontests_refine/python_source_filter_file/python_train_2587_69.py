k,s=map(int,input().split())
ans=0
for i in range(K+1):
    for j in range(K+1):
        if 0<=(s-i-j)<=K:
            ans+=1
print(ans)
