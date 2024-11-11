N,A,B,C,D=map(int,input().split())
S=input()
E=min(C,D)
F=max(C,D)
if S.find('##',A,F)>0:
  print('No')
else:
  if C<D:
    print('Yes')
  else:
    if S.find('...',B,E)>0:
      print('Yes')
    else:
      print('No')
