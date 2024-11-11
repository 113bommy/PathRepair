X = int(input())
S = set()
for i in range(2,X):
  b = 1
  while(i**b<=X):
    S.add(i**b)
    b += 1
ans = max(S)
print(ans)