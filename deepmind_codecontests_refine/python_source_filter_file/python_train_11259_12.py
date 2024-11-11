n,t=map(int,input().split())
a=[]
for i in range(n):
  s,d=map(int,input().split())
  s -= t
  if s < 0: s = s % d
  a.append(s)
print(a)
print(a.index(min(a))+1)