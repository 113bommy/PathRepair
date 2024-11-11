import sys
n,p=map(int,input().split())
s=input()
x=[0 for i in range(p)]
ans=0
if p==2 or p==5:
    for i in range(n):
        if int(s[i])%p==0: ans+=i+1
    print(ans)

else:
    tmp1=1
    tmp2=0
    for i in range(n):
        tmp2=(tmp1*int(s[i])+tmp2)%p
        x[tmp2]+=1
        tmp1=(tmp1*10)%p

    ans+=x[0]
    for i in range(p):
        ans+=x[i]*(x[i]-1)//2
    print(ans)