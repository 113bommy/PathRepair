N, M = map(int, input().split())
SC = [list(map(int, input().split())) for _ in range(M)]
 
for X in range(10**N):
  X = str(X)
  
  #all　すべてがtrueならという意味
  if len(X) == N and all(X[s-1] == str(c) for s, c in SC):
    print(X)
    break
else:
  print(-1)