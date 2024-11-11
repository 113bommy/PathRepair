a,b=map(int,input().split())
s=input()
if s.count('-')==1 and s[a]=='_':
  print("Yes")
else:
  print("No")