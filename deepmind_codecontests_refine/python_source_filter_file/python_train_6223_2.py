s = input()
t = input()
ans = 1000
for i in range(0,len(s)-len(t)):
  cnt = 0
  for (m,n) in zip(s[i:i+len(t)],t):
    if m!=n : cnt += 1
  ans = min(ans,cnt)
  
print(ans)