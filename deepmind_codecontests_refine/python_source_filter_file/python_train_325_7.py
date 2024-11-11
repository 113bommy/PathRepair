n,x,y=list(map(int,input().strip().split()))
s=input()
y=n-y-1
ans=0
for i in range(n-1,n-1-x,-1):
    if i==y:
        ans+=1 if s[i]==0 else 0
    elif s[i]=='1':
        ans+=1
print(ans)
