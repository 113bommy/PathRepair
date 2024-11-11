n,m=map(int,input().split())
b=[]
for i in range(m):
    a= list(map(str, input().split()))
    a.sort(key=len)
    b.append(a[0])
    b.append(a[1])
print(b)
c= list(map(str, input().split()))
for i in c:
    t=b.index(i)
    if t%2==0:print(b[t],end=' ')
    else:print(b[t-1],end=' ')
