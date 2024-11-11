a = int(input())
for _ in range(a):
  n = int(input())
  s = 0
  if (n==1):
    print(0)
  else:
    k = int(n/2)
    print(8*k*(k+1)*(2*k+1)/6)
    