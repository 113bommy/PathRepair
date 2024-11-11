n=int(input())
a,b,c=0,0,0
count=0
for i in range(n):
  s=input()
  count+=s.count('AB')
  if s[0]=='B' and s[-1]=='A':
    a+r=1
  elif s[0]=='B':
    b+=1
  elif s[-1]=='A':
    c+=1
if b==0 and c==0:
  print(count+a-1)
else:
  print(count+a+min(b,c))