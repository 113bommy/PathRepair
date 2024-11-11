N = int(input())
even = True if N % 2 == 0 else False
print(N*(N-1)//2-N//2)
for i in range(1, N):
  for j in range(i+1, N+1):
    if even and i + j != N+1 or not even and i + j == N+1:
      print(i, j)