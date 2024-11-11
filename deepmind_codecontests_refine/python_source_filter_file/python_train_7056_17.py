from collections import deque
S = input()
Q = int(input())
R = 1
Top = deque()
Top.append(S)
for _ in range(Q):
  inp = input()
  if inp[0]=='1':
    R *= -1
  else:
    o, f, c = inp.split()
    if f=='1' and R==-1 or f=='2' and R==1:
      Bot.append(c)
    else:
      Top.appendleft(c)
S = ''.join(Top)
S = S if R==1 else S[::-1]
print(S)