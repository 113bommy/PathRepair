k = int(input())
s = input()

if k < len(s):
  s = s[:k]+"..."
print(s)