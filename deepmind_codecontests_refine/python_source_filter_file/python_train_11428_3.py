N,X,M=map(int,input().split())
l=[X]
p=[-1]*(M+1)
p[X]=0
for i in range(N-1):
    x=(l[-1]**2)%M
    if p[x]>=0:
        break
    l.append(x)
    p[x]=i+1
x=p[x]
y=len(l)-x
print(sum(l[:x])+(N-x)//y*sum(l[x:])+sum(l[x:x+(N-x)%y]))