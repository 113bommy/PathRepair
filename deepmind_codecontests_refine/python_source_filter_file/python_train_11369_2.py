s=input().replace('>',">,").split(',')
print(s)
cnt=0; x=1
for i in range(len(s)-1):
  print(' '*2*cnt+s[i])
  if s[i].count('/')==0 and s[i+1].count('/')==0: cnt+=1
  elif s[i].count('/')==1 and s[i+1].count('/')==1: cnt-=1
  