N, A = map(int, input().split())
x = [int(i) for i in input().split()]

table = [[[0]*(N*A+1) for i in range(N+1)] for j in range(N+1)]
table[0][0][0] = 1

for j in range(1,N+1):
  for k in range(j+1):
    for s in range(N*A+1):
      c = x[j-1]
      if s-c<0:
        table[j][k][s] = table[j-1][k][s]
      elif s-c>=0 and k>=1:
        table[j][k][s] = table[j-1][k][s] + table[j-1][k-1][s-c]
      
ans = 0
for i in range(1,N+1):
  ans += table[N][i][i*A]
print(ans)