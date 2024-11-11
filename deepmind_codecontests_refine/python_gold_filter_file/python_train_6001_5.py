from itertools import permutations

n, m = (int(c) for c in input().split())
s = '#'*(m+2)
for i in range(n):
  s += '#'+input().strip()+'#'
s += '#'*(m+2)
ins = ['0123'.find(c) for c in input().strip()]

c = 0
for d in permutations([1, -1, m+2, -m-2]):
  p = s.find('S')
  for i in ins:
    p += d[i]
    if s[p]=='E': c += 1
    if s[p] in 'E#': break

print(c)