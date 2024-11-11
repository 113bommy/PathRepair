s=input()
t=input()

ans=len(t)
for i in range(len(s)-len(t)+1):
  cnt=0
  for j in range(len(t)):
    if t[j]!=s[j+i]:
      cnt+=1  
  ans=min(cnt,ans)
print(ans)