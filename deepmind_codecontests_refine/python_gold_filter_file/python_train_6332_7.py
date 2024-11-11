I=lambda:list(map(int,input().split()));n,m=I();p=I();l=[i for i in range(n+1)]
def u(x):
 if l[x]!=x:l[x]=u(l[x])
 return l[x]
for _ in[0]*m:x,y=I();l[u(x)]=u(y)
print(sum(u(i)==u(j)for i,j in enumerate(p,1)))