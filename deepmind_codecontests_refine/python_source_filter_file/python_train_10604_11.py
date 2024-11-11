s=input()
t="CODEFESTIVAL2016"
ret=0
for i range(s.len()):
  if s[i] != t[i]:
    ret+=1
print(ret)