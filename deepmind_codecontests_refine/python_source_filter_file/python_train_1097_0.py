t=int(input())
x1=0
y1=0
z1=0
for i in range(t):
      x,y,z=map(int,input().split())
      x1+=x
      y1+=y
      z1+=z
if(x1==0 and y1==0 and z1==0):
      print("Yes")
else:
      print("No")