s=input().rstrip()
for i in range(len(s)):
  if 1 <= i and (s[i-1] == s[i]):
    print(i,i+1)
    exit()
  if 2 <= i and (s[i-2] == s[i]):
    print(i,i+2)
    exit()
print(-1,-1)