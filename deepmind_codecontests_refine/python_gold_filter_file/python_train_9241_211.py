k = int(input())
S = input()
if len(S) <= k:
  print(S)
else:
  print(S[:k]+'...')