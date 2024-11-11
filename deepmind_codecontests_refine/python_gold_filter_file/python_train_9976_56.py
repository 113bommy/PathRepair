X = int(input())
S = set([1])
for i in range(2,X):
  b = 2
  while(i**b<=X):
    S.add(i**b)
    b += 1

ans = max(S)
print(ans)