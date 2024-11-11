a=[int(x) for x in input().split(" ")]
b=[int(x) for x in input().split(" ")]
c=[int(x) for x in input().split(" ")]
d=[int(x) for x in input().split(" ")]
if (a[0]==1 or b[1]==1 or c[2]==1 or d[:3].count(1)>0) and d[3]==1:
    print("YES")
    exit(0)
if (a[1]==1 or b[2]==1 or d[0]==1 or c[:3].count(1)>0) and c[3]==1:
    print("YES")
    exit(0)
if (a[2]==1 or d[1]==1 or c[0]==1 or b[:3].count(1)>0) and b[3]==1:
    print("YES")
    exit(0)
if (d[2]==1 or b[0]==1 or c[1]==1 or a[:3].count(1)>0) and a[3]==1:
    print("YES")
    exit(0)
print("NO")