n=int(input())
s=input()
t=0
pre=s[0]
ans=''
v=0
for i in range(n):
    if s[i]==pre:
        t+=1
    else:
        if v%2==0:
            ans+=pre
            v+=1
        else:
            ans+=pre*min(2,t)
            v+=min(2,t)
        pre=s[i]
        t=1
if v%2==1 and t==1:
    ans+=s[-1]
    v+=1
print(n-v)
print(ans)