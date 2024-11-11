a,b = map(str,input().split())
s = str(input())
if s.count('-') == 1 and s[a+1] == '-':
    print('Yes')
else:
  print('No')
