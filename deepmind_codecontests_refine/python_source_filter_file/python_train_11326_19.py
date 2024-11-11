h,w,a,b = map(int,input().split())
for i in range(a):
  s = '0'*b + '1'*(w-b)
  print(s)
for i in range(h-a):
  s = '1'*b + '0'*(w-b)
  print(s)