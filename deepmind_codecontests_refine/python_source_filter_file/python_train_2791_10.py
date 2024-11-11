N, K = map(int, input().split())
h = list(map(int, input().split()))
 
S = [0] * N

for i in range(1, N):
  S[i] = min(S[_] + abs(h[i] - h[_]) for range(max(0, i-K), i))

print(S[N-1])
