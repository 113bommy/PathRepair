n,*x=map(int,open(0).read().split())
soreted_x=sorted(x)
cnt=0
for a,b in zip(x,soreted_x):
  if a != b:
    cnt+=1
print('YES' if cnt==2 else 'NO')