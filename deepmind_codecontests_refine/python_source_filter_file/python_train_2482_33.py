import re
s=str(input())
s = s.replace('?', '.')
t=str(input())
for i in range(0,len(s)-len(t)):
  if re.match(s[i:i+len(t)],t):
    s=s.replace(".","a")
    print(s[:i]+t+s[i+len(t):])
    exit()
else:
  print("UNRESTORABLE")