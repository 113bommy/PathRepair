k = int(input())
s = input()
if len(s) > k:
  print(s[:k+1]+'...')
else:
  print(s)