N,M=map(int, input().split())
A = [input() for i in range(N)]
B = [input() for i in range(M)]

for i in range(N-M+1):
  for j in range(N-M+1):
    t = True
    for k in range(M):
      if B[k] != A[i+k][j:j+M]:
        t = False
  if t:
    print("Yes")
    exit()
print("No")