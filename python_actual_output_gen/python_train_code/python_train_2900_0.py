t = int(input())
for i in range(t):
  n,x,a,b = map(int,input().split())
  print(min(99,x+abs(a-b)))