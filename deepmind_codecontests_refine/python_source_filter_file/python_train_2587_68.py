a,b=input().split()
a=int(a)
b=int(b)
c=0
for i in range(b+1):
  for k in range(b+1):
    if a<=i+k<=a+b:
      c=c+1
print(c)