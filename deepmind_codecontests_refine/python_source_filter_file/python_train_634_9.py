import sys, math
s=[x for x in input()]
string=[]
last=''
for i in range(len(s)):
  if s[i]=='a' or s[i]=='b':
    if last!=s[i]:
      last=s[i]
      string.append([s[i], 0])
    string[-1][-1]+=1
res=[0]
summa=0
for i in range(len(string)):
  if string[i][0]=='a':
    res.append(string[i][1])
    res[-1]+=string[i][1]*res[-2]
    res[-1]+=res[-2]
    summa+=res[-1]
if len(res)==0:
  print (0)
else:
  print (res[-1]%1000000000+7)