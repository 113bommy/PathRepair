n, k = [int(x) for x in input().split()]
r, s, p = [int(x) for x in input().split()] # グー：r チョキ：s パー：p
t = list(input())

addscoremap = {'r': p, 's': r, 'p': s}

score = 0

for i in range(n):
  if (0 <= i-k) and (t[i] == t[i-k]):
    t[i] = 'x'
    continue
  score += addscoremap[t[i]]

print(score)
