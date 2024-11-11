h,w=map(int,input().split())
if (h-1)*(w-1)==0:
  print(1)
else:
  print(-(-h*w)//2)