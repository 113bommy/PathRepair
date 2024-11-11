a,b=map(int,input().split())
x=max(a,b)
ans=0
for i in range(x+1):
    for j in range(x+1):
        if (i*i+j-a==0) and (j*j+i-b==0):
            ans+=1
print(ans)