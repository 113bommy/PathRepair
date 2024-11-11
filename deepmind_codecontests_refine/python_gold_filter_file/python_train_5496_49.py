M = int(input())
dcs = []
for i in range(M):
  d, c = map(int, input().split())
  dcs.append((d, c))
r = sum([c for d, c in dcs])-1+(sum([d*c for d, c in dcs])-1)//9
print(r)
