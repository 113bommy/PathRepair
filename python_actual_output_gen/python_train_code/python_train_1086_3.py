s = input()
t = input()
count = 0
for i in range(1,min(len(s),len(t))):
  if s[(-1*i)] == t[(-1*i)]:
    count += 1
  else:
    break
print(len(s)+len(t)-2*count)