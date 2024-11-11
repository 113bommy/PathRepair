N, M = map(int,input().split())
X = sorted(map(int,input().split()))

X = sorted([X[i+1]-X[i] for i in range(M-1)])
ans = sum(X[:-(N-1)])
if M <= N:
  ans = 0
print(ans)