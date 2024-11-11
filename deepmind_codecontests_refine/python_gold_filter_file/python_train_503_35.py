n,a=map(int,input().split())
l=list(map(int,input().split()))
for i in range(n):
    l[i]-=a
u=[0]*(3001)
d=[0]*(3001)
ul=[]
dl=[]
z=0
for i in l:
    if i==0:
        z+=1
    elif i<0:
        dl.append(-i)
    else:
        ul.append(i)
        
for i in ul:
    for j in range(3000,-1,-1):
        if u[j]>0 or j==0:
            u[j+i]+=max(1,u[j])
for i in dl:
    for j in range(3000,-1,-1):
        if d[j]>0 or j==0:
            d[j+i]+=max(1,d[j])
ans=0
for i in range(3001):
    ans+=u[i]*d[i]
if ans==0 and z==0:
    print(0)
elif z==0:
    print(ans)
elif ans==0:
    print(2**z-1)
else:
    print((1+ans)*(2**z)-1)
