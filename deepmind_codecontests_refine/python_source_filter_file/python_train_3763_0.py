from sys import stdin
def gcd(a,b):
    while b!=0:
        t=int(a)
        a=int(b)
        b=t%a
    return int(a)
n=int(stdin.readline().strip())
s=list(map(int,stdin.readline().strip().split()))
s1=list(map(int,stdin.readline().strip().split()))
d=dict()
ans=0
ans1=0
for i in range(n):
    try:
        
        x=-s1[i]/s[i]
    except:
        if s1[i]==0:
            ans1+=1
        continue
    y=gcd(s1[i],s[i])
    while y>1:
        s1[i]=s1[i]//y
        s[i]=s[i]//y
        y=gcd(s1[i],s[i])
    if (s[i]<0 and s1[i]<0) or s1[i]<0:
        s[i]=-s[i]
        s1[i]=-s1[i]
    x=str(s1[i])+"/"+str(s[i])
    if s1[i]%s[i]==0:
        x=s1[i]//s[i]
        x=str(x)
    if x not in d:
        
        d[x]=1
    else:
        d[x]+=1
ans=0
for i in d:
    ans=max(d[i],ans)
print(ans+ans1)
    
