s=input()
t=input()
for i in range(200):
  s=s[-1]+s[:-1]
  if s==t:print("Yes")
print("No")