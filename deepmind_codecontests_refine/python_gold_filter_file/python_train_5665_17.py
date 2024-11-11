n=int(input())
a=[]
for i in range(n):
    a.append(list(map(int,input().split())))
u=0
l=0
d=0
for i in range(n):
    u=u+a[i][0]
    l=l+a[i][1]
    if a[i][0]%2!=a[i][1]%2:
        d=d+1
if u%2==0 and l%2==0:
    print(0)
elif u%2==1 and l%2==1:
    if d>0:
        print(1)
    else:
        print(-1)
else:
    print(-1)