n = input()
qx,qy = map(int, input().split())
kx,ky = map(int, input().split())
wx,wy = map(int, input().split())
if (kx-qx)*(wx-qx)>0 and (ky-qy)*(wy-qy):
	print("YES")
else:
	print("NO")
