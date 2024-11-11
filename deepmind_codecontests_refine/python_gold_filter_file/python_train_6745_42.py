s = input()
c = 0
for i in range(len(s)//2):
  if s[i]!=s[-i-1]:
    c += 1
print(c)