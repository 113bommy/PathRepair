n,x,y=map(int,input().split())
s=input()
ans=s[x+1:].count('1')
if s[n-y-1]=='1':
    ans-=1
else:
    ans+=1
print(ans)
