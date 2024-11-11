s,t=open(0).read().split()
res=1001
for i in range(len(s)-len(t)):
  cnt=0
  for j in range(len(t)):
    if s[i+j]==t[j]:
      cnt+=1
  res=min(len(t)-cnt,res)
print(res)