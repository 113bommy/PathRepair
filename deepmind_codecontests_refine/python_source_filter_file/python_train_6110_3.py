n,m=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
b=[100000]*10
for j in range(n):
    b[x[j]]=j
c=[0]*m
for i in range(m):
    c[i]=b[y[i]]
cc=sorted(zip(c,y))
print(cc)
for i in range(m):
    if(cc[i][0]==100000):
        break
    print(cc[i][1],end=" ")