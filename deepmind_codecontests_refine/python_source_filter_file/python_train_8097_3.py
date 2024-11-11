import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

class KmpSearch:
  def __init__(self, word):
    self.word = word
    self.table = [0] * (len(word) + 1)
    self.table[0] = -1
    i, j = 0, 1
    while j < len(self.word):
      matched = self.word[i] == self.word[j]
      if not matched and i > 0:
        i = self.table[i]
      else:
        if matched:
          i += 1
        j += 1
        self.table[j] = i
  def search(self, text):
    table = self.table
    word = self.word
    i, p = 0, 0
    res = []
    while i < len(text):
      if text[i] == word[p]:
        i += 1
        p += 1
      elif p == 0:
        i += 1
      else:
        p = table[p]
      if p == len(word):
        res.append(i - p)
        p = table[p]
    return res

xa = [0] * N
xb = [0] * N
for i in range(N):
  xa[i] = a[i - 1] ^ a[i]
  xb[i] = b[i - 1] ^ b[i]

kmp = KmpSearch(xa)
res = kmp.search(xb + xb[: -1])
rres = []
for x in res: rres.append((N - x, a[0] ^ b[x]))
rres.sort(key = lambda x: (x[0], x[1]))
for r in rres: print(*r)