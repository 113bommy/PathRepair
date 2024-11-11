s=input()
s=list(s)
for i in s:
  if s.count(s[i])%2==1:
    print("No")
    exit()
print("Yes")