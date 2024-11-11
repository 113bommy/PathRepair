A,B,C,K=map(input().split())
if A>=K:
  print(K)
elif A+B>=K:
  print(A)
else:
  print(A+A+B-K)