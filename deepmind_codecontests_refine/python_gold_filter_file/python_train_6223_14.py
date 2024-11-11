s,t=input(),input()
be=len(t)
for i in range(len(s)-len(t)+1):
  ct=0
  for j in range(len(t)):
    if s[i+j]!=t[j]:
      ct+=1
  if be>ct:
    be=ct
print(be)