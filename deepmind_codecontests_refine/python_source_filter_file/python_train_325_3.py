n,x,y=map(int,input().split())
s=input()
ans=0
for i in range(x-1):
    if(i==y):
        if s[n-i-1]=='0':
            ans+=1
    else:
        if s[n-i-1]=='1':
            ans+=1
print(ans)