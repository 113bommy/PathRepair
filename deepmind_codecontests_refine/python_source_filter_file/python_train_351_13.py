from math import ceil

n=int(input())
a=[int(x) for x in input().split()]
a.sort()
x=a[-1]
an=0
z=sum(a)

print(x,ceil(z/(n-1)))