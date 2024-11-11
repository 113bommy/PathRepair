w,h,n=map(int,input().split())
sq=[0,-w,0,-h]		#左端，右端，下端，上端

for i in range(n):
  x,y,b=map(int,input().split())
  dumy = [x,-x,y,-y]
  a=b-1
  if sq[a]<dumy[a]:
    sq[a]=dumy[a]


if -sq[1]-sq[0]<0:
  s=0
elif -sq[3]-sq[2]<0:
  s=0
else:
  s=(-sq[1]-sq[0])*(-sq[3]-sq[2])

print(s)