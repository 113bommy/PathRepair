n,m =  map(int,input().split())

min_cost = 2
while n:
  a,b = map(int,input().split())
  if min_cost > (a/b):
     min_cost = a/b

  n -= 1

print(round(min_cost * m,8))


