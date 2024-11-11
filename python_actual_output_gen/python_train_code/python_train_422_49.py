s1=['q','w','e','r','t','y','u','i','o','p',
'a','s','d','f','g','h','j','k','l',';',
'z','x','c','v','b','n','m'',','.','/']
s=input()
ss=list(input())
r=[]
if(s=='R'):
  for i in range(len(ss)):
    if ss[i] in s1:
      index=s1.index(ss[i])
      r.append(s1[index-1])
for k in r:
  print(k,end="")
res=[]
if(s=='L'):
  for i in range(len(ss)):
    if ss[i] in s1:
      index=s1.index(ss[i])
      res.append(s1[index+1])
for k in res:
  print(k,end="")