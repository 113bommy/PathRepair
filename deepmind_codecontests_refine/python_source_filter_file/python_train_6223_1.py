s=input()
t=input()
max_=0
for i in range(len(s)-len(t)):
  c = 0
  for j in range(len(t)):
    if s[i+j] == t[j]:
      c += 1
  max_ = max(max_, c)
print(len(t)-max_)