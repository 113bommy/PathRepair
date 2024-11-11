n = int(input())
t = [0] + list(map(int,input().split()))
s = sum(t)
for _ in [0]*int(input()):
  p,x = map(int,input().split())
  pritn(s-t[p]+x)
