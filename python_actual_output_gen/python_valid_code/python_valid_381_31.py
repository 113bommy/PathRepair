for _ in range(int(input())):
  t, x, y = map(int,input().split())
  if (t+x+y)%2 + (t<x+y):
    s = 0
    break
  s = 1
print("YNeos"[s::2])
    