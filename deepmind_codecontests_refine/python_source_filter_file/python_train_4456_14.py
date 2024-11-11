N=int(input())
T=[[] for _ in range(N)]
for i in range(N):
  n=int(input())
  for j in range(n):
    T[i].append(tuple(map(int,input().split())))
ans=0
for i in range(N**2):
  true,t,f=set(),set(),set()
  for j in range(N):
    if i>>j&1:
      true.add(j+1)
      for a,b in T[j]:
        if b:
          t.add(a)
        else:
          f.add(a)
  if t<=true and not(f&true):
    ans=max(ans,len(true))
print(ans)