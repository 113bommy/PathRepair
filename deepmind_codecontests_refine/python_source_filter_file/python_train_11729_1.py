turns = int(input())
pos = ["Kuro", "Shiro","Katie"]
beauty = []
for i in range(3):
  s = input()
  l = len(s)
  freq = dict()
  for i in s :
    freq[i] = freq.get(i,0)
    freq[i] += 1
  ma = max(freq.values())
  cas = [min(turns+ma,l)]
  if turns == 1 and l == ma:
    cas.append(l-1)
  beauty.append(min(cas))

if beauty.count(max(beauty)) == 2:
  print("Draw")
else:
  print(pos[beauty.index(max(beauty))])