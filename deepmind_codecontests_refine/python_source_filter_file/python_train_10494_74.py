n,a,b,c,d=map(int,input().split())
s=input()
if '##'in s[min(a,b,c,d):max(a,b,c,d)-1]:
  print('No')
else:
  if c<d:
    print('Yes')
  else:
    if '...' in s[b-2:d]:
      print('Yes')
    else:
      print('No')
