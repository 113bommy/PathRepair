a,b=input().split()
a=int(a)
b=int(b)
c=0
for i in range(a):
  for k in range(a):
    if a-b<i+k<=a:
      c=c+1
print(c)