N, Y = map(int,input().split())
a = -1
b = -1
c = -1
for i in range(N+1):
  for j in range(N+1-i):
    if i*9000 + j*4000 == Y - 1000*N:
      a = i
      b = j
      c = N-i-j
print(a, b, c)