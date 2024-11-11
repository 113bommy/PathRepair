m, n = map(int, input().split())
if m == 1:
    print(1)
else:
  print(1/n + (n-1)/n*(m-1)/(n*m-1))