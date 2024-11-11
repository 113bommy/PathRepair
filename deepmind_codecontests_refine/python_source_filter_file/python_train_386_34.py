n=int(input())
s=sorted(list(map(int,input().split())))
ans=ans2=0
a=list(range(1,n+1))
b=a[1::2]
a=a[::2]
for i in range(n//2):
    ans+=abs(s[i]-a[i])
    ans2+=abs(s[i]-a[i])
print(min(ans,ans2))