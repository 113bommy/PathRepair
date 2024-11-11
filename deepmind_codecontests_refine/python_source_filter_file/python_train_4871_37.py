h,w = map(int, input().split())
k = h*w
if (h-1)(w-1)==0:
  print(1)
else:
  print(k-int(k/2))
