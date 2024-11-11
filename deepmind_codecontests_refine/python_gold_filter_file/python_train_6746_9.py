import bisect
n=int(input())
h=[]
for i in range(n):
  a=int(input())
  if len(h)==0:
    h.append(-1*a)
  elif (-1)*a>=h[-1]:
    h.append(-1*a)
  else:
    index=bisect.bisect_right(h,-1*a)
    h[index]=-1*a
print(len(h))
