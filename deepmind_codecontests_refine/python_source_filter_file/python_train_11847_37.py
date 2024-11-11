N, A, B=map(int, input().split())
if A%2==B%2:
  print((B-A)//2)
else:
  print(min((A+B-1)//2, (B-A+1)//2))