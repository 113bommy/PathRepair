a,v=map(int,input().split())
b,w=map(int,input().split())
t=int(input())
x=(w-v)*t
if x>=abs(a-b):
  print('YES')
else:
  print('NO')
