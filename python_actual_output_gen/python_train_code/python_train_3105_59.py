s = input()
t = input()
ans = 0
for i in range(3):
  if s[i]==s[t]:
    ans+=1
print(ans)