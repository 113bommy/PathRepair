N = int(input())
A = list(map(int, input().split()))

mina = min(A)
mini = A.index(mina)
maxa = max(A)
maxi = A.index(mixa)

if mina >= 0:
  print(N-1)
  for i in range(N-1):
    print("{} {}".format(i+1, i+2))
elif maxa < 0:
  print(N-1)
  for i in range(N-1):
    print("{} {}".format(N-i, N-i-1))
else:
  if -mina < maxa:
    print(2*N-1)
    for i in range(N):
      print("{} {}".format(maxi+1, i+1))
    for i in range(N-1):
      print("{} {}".format(i+1, i+2))
  else:
    print(2*N-1)
    for i in range(N):
      print("{} {}".format(mini+1, i+1))
    for i in range(N-1):
      print("{} {}".format(N-i, N-i-1))