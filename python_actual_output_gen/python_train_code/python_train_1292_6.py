n = int(input())
t = list(map(int,input().split()))
for _ in int(input()):
  p,x = map(int,input().split())
  l=t.copy()
  l[p-1] = x
  print(sum(l))

