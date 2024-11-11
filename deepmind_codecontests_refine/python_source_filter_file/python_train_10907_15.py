X, K, D = map(int, input().split())
x = abs(X)

if x//D <= K:
  if (K-x//D)%2 == 0:
    print(min(x, x%D))
  else:
    print(min(x, abs(D-x%D)))
else:
  print(x-K*D)