n,k=map(int,input().split())
s=input()
i=n-1
while i>0:
    if s[:i]==s[-i:]:
        break
    i-=1
if i>0:
    x,y=s[:-i],s[-i:]
    print(x*k+y)
else:print(s*k)
