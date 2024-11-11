s = input()
t = ''

for i in range(len(s)):
  if s[i] == 'B':
    t = t[:-1]
  else:
    t += i
    
print(t)