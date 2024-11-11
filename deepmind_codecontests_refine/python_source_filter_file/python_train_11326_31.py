h,w,a,b=map(int,input().split())

for i in range(h-a):
  print("0"*(w-b)+"1"*b)
for j in range(a):
  print("1"*(w-b)+"0"*b)