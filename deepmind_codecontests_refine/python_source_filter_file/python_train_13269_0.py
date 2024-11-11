#!/usr/bin/env python3

'''exceeds time-limit on the 51 testcase'''

from collections import Counter

def main():
  n = int(input())
  numbers = list(map(int, input().split()))

  permutations, checked = [], []
  cnt = Counter()
  for number in numbers:
    cnt[number] += 1
    permutations.append(cnt[number] + 1)
    # checked.append(number)

  buff_k, buff_d = 0, 0

  if cnt[1] == 0:
    return "-1"

  for d, k in sorted(cnt.items()):
    if (k <= buff_k or buff_k == 0) and (d == buff_d + 1 or buff_d == 0):
      buff_k, buff_d = k, d
    else:
      return "-1"

  return "".join([str(cnt[1]), '\n', " ".join(list(map(str, permutations)))])

if __name__ == "__main__":
  print(main())
