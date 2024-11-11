N, L = map(int, input().split())
A = list(map(int, input().split()))
d = [A[i] + A[i+1] for i in range(N-1)]
if max(d) < L:
  print("Impossible")
else:
  print("Possible")
  j = 0
  while d[j] != max(d):
    j += 1
  for i in range(j):
    print(i+1)
  for i in range(j, N-1):
    print(N-i+j-1)