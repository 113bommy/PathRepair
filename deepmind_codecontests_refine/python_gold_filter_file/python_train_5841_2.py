n = int(input())
ax, ay = [int(i) for i in input().split()]
bx, by = [int(i) for i in input().split()]
cx, cy = [int(i) for i in input().split()]
mb = 0
if bx < ax and by < ay:
    mb = 1
if bx > ax and by < ay:
    mb = 2
if bx < ax and by > ay:
    mb = 3
if bx > ax and by > ay:
    mb = 4
mc = 0
if cx < ax and cy < ay:
    mc = 1
if cx > ax and cy < ay:
    mc = 2
if cx < ax and cy > ay:
    mc = 3
if cx > ax and cy > ay:
    mc = 4


if mb == mc:
    print("YES")
else:
    print("NO")
