f=lambda:map(int,input().split())
n,a,b=f()
l=[[*f()] for i in range(n)]
k=[]
for i in range(0,n):
    if l[i][0]!=a:
        m=(l[i][1]-b)/(l[i][0]-a)
    else:
        m=-1
    if m not in k:
      k.append(m)
print(len(k))
    