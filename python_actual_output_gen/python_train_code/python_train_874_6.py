s=input()
t=input()
f=0
e=5
flg=0
while e<=len(s):
  tmp=s[f:e]
  for i in range(len(t)):
    if tmp[i]!=t[i] and tmp[i]!='?':
      break
    if i==len(t)-1:
      ans=s[:f]+t+s[e:]
      flg=1
  f+=1
  e+=1
if flg==0:
  print('UNRESTORABLE')
else:
  print(ans.replace('?','a'))