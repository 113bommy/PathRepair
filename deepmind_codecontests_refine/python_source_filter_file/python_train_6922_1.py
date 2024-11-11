n,m=[int(i) for i in input().split()]
x,y=[int(i) for i in input().split()]
a=list(map(int,input().split()))[:n]
b=list(map(int,input().split()))[:m]
a.sort()
b.sort()
c=a[:x]
d=b[:y]
c.sort()
d.sort()
if c[-1]<d[0]:
    print("YES")
else:
    print("NO")
