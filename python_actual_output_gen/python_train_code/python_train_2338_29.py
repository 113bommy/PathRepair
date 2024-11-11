s = input()
h = 0
for i in range(len(s)//2):
  if s[i] != s[s-i-1]:
    h += 1
print(h)