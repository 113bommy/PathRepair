A,V=map(int,input().split())
B,W=map(int,input().split())
t=input()
T=int(t)

if abs(B-A)+(V-W)*T <=0:
  print('YES')
else:
  print('NO')
