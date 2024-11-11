n,a,b = [int(i) for i in input().split()]
if (b - a)%2:
  print((b-a-1)//2 + 1 + min(a-1,b-1))
else:
  print((b-a)//2)