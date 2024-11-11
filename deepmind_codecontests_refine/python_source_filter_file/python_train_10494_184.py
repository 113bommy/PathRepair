N,A,B,C,D = map(int,input().split())
S = input()

if not(S[A:C-1].find('##')!=-1 or S[B:D-1].find('##')!=-1):
  if C<D:
    print('Yes')
  elif S[B:D-1].find('...')!=-1:
    print('Yes')
  else:
    print('No')
else:
  print('No')