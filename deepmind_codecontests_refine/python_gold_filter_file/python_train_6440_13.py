N, A, B = input().split(' ')
N = int(N)
A = int(A)
B = int(B)
S = []
S = list(input())
JS = 0
AS = 0
OT = 0

for i in range(N):
  if S[i] == 'a' and A+B > JS+AS:
    print('Yes')
    JS += 1
  elif S[i] == 'b' and A+B > JS+AS and AS < B:
    print('Yes')
    AS += 1
  else:
    print('No') 