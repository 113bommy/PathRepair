s=list(input())
l=[len(s)]
for i in range(len(s)-1):
  if s[i]!=s[i+1]:
    l.append(max(i+1,len(s)-i-1))
print(min(l))