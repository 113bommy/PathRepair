n = int(input())
if n%2==1:
  print(0)
  exit()
n /= 2
if n%2==0:
  print(n//2-1)
else:
  print(n//2)