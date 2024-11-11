import sys
n = input()
qx,qy = map(int, input().split())
kx,ky = map(int, input().split())
wx,wy = map(int, input().split())
if kx-qx > 0 and wx-qx > 0:
    if ky-qy > 0 and wy-qy > 0:
        print('YES')
        sys.exit()
    if ky-qy < 0 and wy-qy < 0:
        print('YES')
        sys.exit()
if kx-qx < 0 and wx-qx < 0:
    if ky-qy > 0 and wy-qy > 0:
        print('YES')
        sys.exit()
    if ky-qy < 0 and wy-qy < 0:
        print('YES')
        sys.exit()
print('NO')