s = input()
t = 0
for i in range(len(s)):
  if s[i] != s[::-1][i]:
    t += 1
print(t//2)