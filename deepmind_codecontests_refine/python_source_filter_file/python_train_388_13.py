def cheess(n,p):
  a=0
  for i in range(n//2):
    a+=(abs((p[i]-1)-(i*2)))
  return a
n=int(input())
p=[int(x) for x in input().split()]
ap=[(n+1)-x for x in p]
ap.reverse()
print(min(cheess(n,p),cheess(n,ap)))