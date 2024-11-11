a = int(input())
b = input()
if len(b) <= a:
  print(b)
else:
  print(b[:a]+'...')