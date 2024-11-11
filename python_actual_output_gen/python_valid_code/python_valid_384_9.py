ret=0
s=input()
for i in range(len(s)-1):
  if s[i]==s[i+1]:
    ret+=1
print(ret)