a=int(input())
b=int(input())
c=int(input())
x=int(input())
t=0
for i in range(a+1):
  for j in range(c+1):
    for k in range(c+1):
      if 10*i+2*j+k==x/50:
        t+=1
print(t)