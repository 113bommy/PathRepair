S = input()
N = len(S)

if S[:(N-1)//2] == S[(N+2)//2:]:
  print('Yes')
else:
  print('No')