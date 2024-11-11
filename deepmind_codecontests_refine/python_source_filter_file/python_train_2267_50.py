X, N = map(int, input().split())
p = list(map(int, input().split()))
S = []

for i in range(101):
  if i in p:
    S.append(101)
  else:
    S.append(abs(i-X))
 
print(S.index(min(S)))