w,h,x,y,r = map(int, input().split())
if 0<=x-1 and x+1<=w and 0<=y-1 and y+1<=h:
  print('Yes')
else:
  print('No')