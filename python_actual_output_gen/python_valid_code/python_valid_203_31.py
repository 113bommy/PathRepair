t = int(input())
for _ in range(t):
  n, m = map(int, input().split())
  if m <= 1:
    print(0)
  elif m == 2:
    print(n)
  else:
    print(2*n)
  
