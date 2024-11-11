a,b=tuple(input().split(" "))
if b=="0":
    print("YES")
    exit(0)
a=int(a)
b=int(b)
c=[int(x) for x in input().split(" ")]
c.sort()
if 1 in c or a in c:
    print("NO")
    exit(0)
for x in c:
    if x in c and x+1 in c and x+2 in c:
        print("NO")
        exit(0)
print("YES")