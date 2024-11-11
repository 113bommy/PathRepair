from collections import Counter
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ca=Counter(a)
cb=Counter(b)
for k in cb:
    if k in ca:
        if cb[k]+ca[k]>n:
            print('No')
            exit()
tmpc=0
tmpd=0
c=[0]
d=[0]
for i in range(1,n+1):
    if i in ca:tmpc+=ca[i]
    if i in cb:tmpd+=cb[i]
    c.append(tmpc)
    d.append(tmpd)
x=-n
for i in range(n):
    x=max(x,c[i]-d[i-1])
ans=b[-x:]+b[:-x]
print('Yes')
print(*ans,sep=' ')
exit()
print(c)
print(d)