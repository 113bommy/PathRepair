h,w=map(int,input().split())
if h==1 and w==1:
  print('0')
else:
  print((h*w+1)//2)
