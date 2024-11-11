a={};b={};c={};ans=0
n=int(input())
for i in range(n):
    x,y=map(int,input().split())
    if x in a:
        a[x]+=1
    else:
        a[x]=1
    if y in b:
        b[y]+=1
    else:
        b[y]=1
    if (x,y) in c:
        c[(x,y)]+=1
    else:
        c[(x,y)]=0
for i in a:
    ans+=a[i]*(a[i]-1)//2
for i in b:
    ans+=b[i]*(b[i]-1)//2
for i in c:
    ans-=c[i]*(c[i]-1)//2
print(ans)