a=[int(q) for q in input().strip().split()]
b=[int(q) for q in input().strip().split()]
c=set(b)
min=100000
for m in c:
    t=b.count(m)
    if t<min:
        min=t
if a[0]<3:
    print(0)
else:
    print(min)