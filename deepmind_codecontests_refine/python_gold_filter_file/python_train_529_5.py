a=list(map(int,input().split(' ')))
t=0
c=0
for i in range(a[0]):
    l=list(map(int,input().split(' ')))
    c=c+((l[0]-t)//a[2])
    t=l[1]+l[0]
c=c+((a[1]-t)//a[2])
print(c)
