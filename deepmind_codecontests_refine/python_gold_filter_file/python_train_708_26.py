a,b = map(int,input().split())
s = str(input())
if s.count('-') == 1 and s[a] == '-':
  print('Yes')
else:
  print('No')
