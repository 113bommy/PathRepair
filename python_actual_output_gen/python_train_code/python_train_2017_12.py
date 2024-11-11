n=int(input())
ax,ay=map(int,input().split())
bx,by=map(int,input().split())
cx,cy=map(int,input().split())
f=0
if bx<ax and by<ay and cx<ax and cy<ay:
	f=1
if bx<ax and by>ay and cx<ax and cy>ay:
	f=1
if bx>ax and by<ay and cx>ax and ay<ay:
	f=1
if bx>ax and by>ay and cx>ax and ay>ay:
	f=1
if f==1:
	print("YES")
else:
	print("NO")