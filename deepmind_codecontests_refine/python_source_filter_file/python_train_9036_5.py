S = input()
ans = 0
tmp = 0
for i in range(len(S)):
  if S[i] == 'W':
    ans+=i-tmp
  else:
    tmp+=1
print(ans)