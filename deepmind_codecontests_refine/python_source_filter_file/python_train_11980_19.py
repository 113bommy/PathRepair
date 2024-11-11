W,H,x,y,r=map(int,input().split())
if !(x+r>W or r>x or r>y or y+r>H):
 print("Yes")
else :
 print("No")