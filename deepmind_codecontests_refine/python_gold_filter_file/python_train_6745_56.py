s=input()
c=0
for i in range(int(len(s)/2)):
  if s[i] != s[len(s)-1-i]:
    c=c+1
print(c)