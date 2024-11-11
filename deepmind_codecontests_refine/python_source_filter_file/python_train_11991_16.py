# -*- coding: utf-8 -*-

def readInts():
  return [int(s) for s in input().split(" ")]

def is_sub(s, t):
  i = 0
  j = 0
  while i < len(s) and j < len(t):
    if s[i] == t[j]:
      j += 1
    i += 1
  return j == len(t)

def main():
  s = input()
  t = input()

  ans = 0
  for l in range(len(s) - 1):
    for r in range(l, len(s)):
      if is_sub(s[0:l] + s[r+1:], t):
        ans = max(ans, r - l + 1)
  print(ans)

if __name__ == "__main__":
  main()
