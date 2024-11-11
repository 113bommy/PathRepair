X,K,D = map(int,input().split())
X = abs(X)
if X >= K * D:
  print(X-K*D)
  exit()
X = X % D
K -= X // D
print(D-X if K%2 else X)