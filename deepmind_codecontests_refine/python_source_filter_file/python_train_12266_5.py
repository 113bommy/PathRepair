import math
N, A = map(int, input().split())
X = list(map(int, input().split()))
L = ([x-A for x in X])
S = L[0]
for i in range(1, N):
  S = math.gcd(S,L[i])
print(S)