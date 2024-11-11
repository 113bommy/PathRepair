N,A,B=map(int, input().split())
S=input().split()
cntA=0
cntB=0
for s in S:
  if s == 'c':
    print('No')
    continue
  if s == 'a' and (cntA+cntB) < A+B:
    print('Yes')
    cntA +=1
  elif (s == 'b') and ((cntA+cntB) < A+B) and (cntB < B):
    print('Yes')
    cntB +=1
  else:
    print('No')