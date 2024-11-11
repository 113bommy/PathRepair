n=int(input())
l,r,s=[],[],[]
for i in range(n):
  a,b=map(int,input().split())
  l.append(a)
  r.append(b)
  s.append((a,b)) 
l=sorted(l)[::-1]
r=sorted(r)
if (l[0],r[0]) in s:
  print(max(r[1]-l[1],0))
else:
  print(max(r[0]-l[1],r[1]-l[0],0))
