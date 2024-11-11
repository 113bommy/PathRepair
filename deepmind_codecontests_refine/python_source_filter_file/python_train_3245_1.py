a=list(map(int,input().split()))
b=[]
for i in range(a[0]):
    c=int(input())
    b.append(c)
d=set(b)
d=list(d)
e=[]
for i in range(len(d)):
    x=b.count(d[i])
    e.append(x)
k=0
for i in range(len(e)):
    if e[i]%2==1:
        k=k+1
print(int(k/2))