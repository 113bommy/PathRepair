k,s=map(int,input().split())
ans=0


for i in range(k+1):
    for j in range(k+1):
        if 0<=i+j-s<=k:
            ans+=1

print(ans)
