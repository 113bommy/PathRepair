d=list(map(int, input().split()))
s=sum(d)/2
if s%1!=0:
    print("NO")
    exit()
d.sort()
if d[5]+d[0]+d[1]>s:
    print("NO")
    exit()
e=d[5]-d[0]
if e in d[1:5]:
    print("YES")
    exit()
e=d[5]-d[1]
if e in d[2:5]:
    print("YES")
    exit()
e=d[5]-d[2]
if e in d[3:5]:
    print("YES")
    exit()
print("NO")
