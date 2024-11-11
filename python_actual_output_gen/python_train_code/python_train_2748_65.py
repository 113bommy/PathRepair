import sys
s=input()
k=int(input())
for i in range(len(s)):
  if s[i]!="1":
    print(s[i])
    sys.exit()
print(1)
