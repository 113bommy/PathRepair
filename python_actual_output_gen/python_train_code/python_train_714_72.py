a,v=map(int,input().split())
b,w==map(int,input().split())
t=int(input())
d=abs(a-b)
if d<=(v-w)*t:
  print('Yes')
else:
  print('No')