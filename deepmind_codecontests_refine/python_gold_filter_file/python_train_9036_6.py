s=input()
a=0
c=0
for i in range(len(s)):
  if s[i]=="W":
    a+=i
    c+=1
b=c*(c-1)//2
print(a-b)