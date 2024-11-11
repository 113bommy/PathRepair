A,V=map(int,input().split())
B,W=map(int,input().split())
T=int(input())
if abs(B-A)<=T*(V-W):
  print('Yse')
else:
  print('No')