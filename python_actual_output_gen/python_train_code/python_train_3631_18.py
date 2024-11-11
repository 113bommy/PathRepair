n,m=map(int,input().split())

a=[]
b=[]
for i in range(m):
    x,y=input().split()
    a.append(x)
    b.append(y)

c=list(input().split())

for i in range(n):
    
    if len(b[a.index(c[i])])<=len(a[a.index(c[i])]):
        print(b[a.index(c[i])],end=" ")
    else:
        print(a[a.index(c[i])],end=" ")
