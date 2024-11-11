import math
n=int(input())
x=math.floor(n**0.5)

while 1:
  if n % x ==0:
    break
  x-=1

print(max(len(str(int(n/x))),len(str(x))))