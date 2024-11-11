s = input()
t = input()

ans = len(t)
for i in range(len(s)-len(t)+1):
  tmp=0
  for j in range(len(t)):
    if t[j] != s[i+j]:
      tmp+=1
  ans = min(tmp,ans)
  
print(ans)