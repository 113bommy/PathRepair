# coding: utf-8
required = [4,8,15,16,23,42]

def good(seq, n):
  current = before = 0
  count = 7 * [0]
  count[0] = n

  for i in range(len(seq)):
    if seq[i] in required:
      current = required.index(seq[i]) + 1
      before = current - 1
      if count[before] > 0:
        count[before] -= 1
        count[current] += 1

  return n - (count[6] * 6)

n = int(input())
seq = list(map(int, input().split()))
print(good(seq, 83333 * 6))