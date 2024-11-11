L = []
for i in range(int(input())):
  L.append(input())
for j in ['AC','WA','TLE','RE']:
  print(j,'x',L.count(j))