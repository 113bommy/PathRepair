s = input()
m = 0
for i in range((len(s)-1)//2):
  if s[:i] == s[i:2*i]:
    m = 2 * i
print(m)