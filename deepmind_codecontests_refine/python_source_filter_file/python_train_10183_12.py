a = list(map(lambda x: int(x), input().split()))
N = a[0]
K = a[1]
sushis = []
for i in range(1, N):
  sushis.append(list(map(lambda x: int(x), input().split())))

sushis.sort(key=lambda x:x[1], reverse=True)

netas = set()
duplicates = []

choices = sushis[:K]

for choice in choices:
  if choice[0] in netas:
    duplicates.append(choice[1])
  else:
    netas.add(choice[0])

p = sum(map(lambda x: x[1], choices)) + len(netas)**2
answer = p

for sushi in sushis[K:]:
  if sushi[0] not in netas and duplicates:
    netas.add(sushi[0])
    duplicate = duplicates.pop()
    p += (sushi[1] - duplicate) + 2*len(netas) - 1
    answer = max(answer, p)

print(answer)