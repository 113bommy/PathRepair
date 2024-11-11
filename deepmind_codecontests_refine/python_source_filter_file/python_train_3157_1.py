import sys
input=sys.stdin.buffer.readline

for t in range(int(input())):
  N=int(input())
  S=list(input())
  a,b,c=0,0,0
  for i in range((N+1)>>1):
    if i==N-i-1:
      if S[i]==48:
        a+=1
    elif S[i]==48 and S[N-i-1]==48:
      b+=1
    elif S[i]==48 or S[N-i-1]==48:
      c+=1
  if a==0:
    if b==0 and c==0:
      print('DRAW')
    elif b>0 and c==0:
      print('BOB')
    else:
      print('ALICE')
  else:
    if b==0 and c==0:
      print('BOB')
    elif b==0 and c>0:
      print('DRAW')
    else:
      print('ALICE')