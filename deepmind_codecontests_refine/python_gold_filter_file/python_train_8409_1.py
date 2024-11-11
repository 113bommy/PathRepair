import sys
x=int(input())
for i in range(x,2*x+1):
  for j in range(2,int(i**0.5)+1):
    if i%j==0:
      break
  else:
    print(i)
    sys.exit()