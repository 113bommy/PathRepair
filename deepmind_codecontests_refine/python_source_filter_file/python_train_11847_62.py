N, A, B = map(int, input().split())

dif = B-A
if dif%2 == 0:
  print(int(dif/2))
else:
  print(min(A-1, N-B)+1+dif//2)
