n,x=map(int,input().split())
l=[[0,1]]
ans=0
p=n
while(n):
    a,b=map(int,input().split())
    if n!=1:
        l.append([a,b+1])
        ans=ans+b-a+1
    else:
        l.append([a,b])
        ans=ans+b-a+1
    
    n=n-1
for i in range(p-1):
    ans=ans+(l[i+1][0]-l[i][1])%x
print(ans)    