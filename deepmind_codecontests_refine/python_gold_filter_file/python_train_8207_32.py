n=int(input())
x=int(n/11*2)
if n % 11 in [0, 6]:
  print(x)
else:
  print(x+1)
