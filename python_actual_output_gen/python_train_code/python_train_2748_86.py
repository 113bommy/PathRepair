s=input()
k=int(input())
for i,c in enumerate(s):
  if c!='1' or i>=k:
    break
print(c)