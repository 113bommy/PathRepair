N = int(input())
A = input()
B = input()
C = input()

ans = 0

for i in range(N):
  S = set(A[i], B[i], C[i])
  ans += S.__len__() - 1

print(ans)