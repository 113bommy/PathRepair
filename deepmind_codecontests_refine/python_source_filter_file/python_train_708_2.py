a,b=map(int,input().split())
s=input()
d=s[:a]+s[a+1:]
if s[a]=='-' and '-' not in d:
  print('YES')
else:
  print('NO')