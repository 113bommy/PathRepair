N, K = map(int, input().split())
S = input()
L = [0]
X = ['1']
pos = 0
for i in range(N):
  if S[i] != X[pos]:
    L.append(1)
    X.append(S[i])
    pos += 1
  else:
    L[pos] += 1
while pos < 2 * K + 4:
  L.append(0)
  X.append('1')
  pos += 1
L.append(0)
X.append('1')
n = len(L)
for i in range(1, n):
  L[i] += L[i-1]
M = L[2*K]
for i in range(1, n-2*K):
  if X[i] == '1':
    M = max(L[2*K+i] - L[i-1], M)
print(M)