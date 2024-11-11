x,y = map(int,input().split())
if(x<y and x*y>=0):
  print(y-x)
elif(y<x and x*y>0):
  print(2+x-y)
else:
  print(abs(abs(y)-abs(x))+1)
