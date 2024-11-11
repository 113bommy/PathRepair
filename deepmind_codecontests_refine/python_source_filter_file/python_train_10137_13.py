n=int(input())
s = input()

iseven = n // 2 == 0

if iseven:
  ns = '-'.join(s[i:i+2] for i in range(0, len(s), 2))
else:
  ns = s[0] + '-'.join(s[i:i+2] for i in range(1, len(s), 2))
print(ns)