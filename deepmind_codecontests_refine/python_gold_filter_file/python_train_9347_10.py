N = int(input())
A = list(map(int,input().split()))
S = sum(A)
P = 10**20
X = 0
for i in range(N):
  X = X + A[i]
  P = min(P,abs(S-X*2))
print(P)