A,B,K = map(int, input().split())
X = list(range(A,B+1))

for _ in sorted(set(X[:K]) | set(X[-K:])):
  print(_)