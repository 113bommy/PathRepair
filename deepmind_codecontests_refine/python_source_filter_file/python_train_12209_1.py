t=int(input())
for i in range(t):
  n,T=map(int, input().split())
  s=[int(i) for i in input().split()]
  h=0
  d=[]
  for i in range(n):
    if s[i]<T/2:
      d.append(0)
    elif s[i]>T/2:
      d.append(1)
    else:
      d.append(str(h))
      h=(h+1)%2
print(*d)