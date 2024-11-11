n=int(input())
b=[int(x) for x in input().split()]
a=[0]*n
a[-1]=b[0]
for i in range(1,len(b)):
    a[-i-1]=min(a[-i],b[i]-a[i-1])
    a[i]=b[i]-a[-i-1]
print(*a)