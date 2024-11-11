s,t=open(0).read().split()
res=len(t)
for i in range(len(s)-len(t)+1):
  cnt=0
  for j in range(len(t)):
    if s[i+j]==t[j]:
      cnt+=1
  res=min(len(t)-cnt,res)
print(res)