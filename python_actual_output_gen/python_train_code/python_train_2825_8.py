n=int(input())
a=list(map(int,input().split()))
b=[1]
c=[a[0]]
for i in range(1,n):
    if(a[i]*2<=a[0]):
        b.append(i+1)
        c.append(a[i])
x=sum(a)
if(a[0]>=x//2):
    print(len(b))
    print(*b)
else:
    print(0)
