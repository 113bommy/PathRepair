h,w,a,b=map(int,input().split())
s="0"*a+"1"*(w-a)
t="1"*a+"0"*(w-a)
for i in range(h):
  print(s)
for i in range(b-h):
  print(t)