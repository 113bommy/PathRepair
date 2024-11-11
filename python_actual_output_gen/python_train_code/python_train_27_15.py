L = []
for i in range(int(input())):
  L.append(input())
print(L)
for j in ['AC','WA','TLE','RE']:
  print(j,'x',L.count(j))