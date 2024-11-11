s = input()
n = len(s) + 1
t = [0]*n
for i in range(n-1):
  if s[i] == '<':
    t[i+1] = t[i] + 1
for i in range(n-2,-1,-1):
  if s[i] == '>':
    t[i] = max(t[i],t[i+1]+1)
print(sum(t))