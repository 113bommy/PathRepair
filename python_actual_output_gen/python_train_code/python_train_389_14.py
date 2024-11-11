c= []
d = []
v =[]
for _ in range(int(input())):
    a= list(map(int, input().split()))
    c.append(a[0])
    d.append(a[1])
    v.append(a[2])
if sum(c)+sum(d)+sum(v) == 0:
    print("YES")
else:
    print("NO")


