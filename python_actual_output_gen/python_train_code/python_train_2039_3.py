M, K = map(int, input().split())
A = list(map(int, input().split()))

ans = 0
accum = [0]
d = {0 : 1}

for i, a in enumerate(A):
  accum.append((accum[-1] + a - 1)%K)
  if i > K - 1:
    d[accum[i-K]] -= 1
  
  if accum[-1] in d:
    ans += d[accum[-1]]
    d[accum[-1]] += 1
  
  else:
    d[accum[-1]] = 1

print(ans)