x=int(input())
d=0
for i in range(x):
  y=list(map(int,input().split()))
  a=int(y[0])
  b=int(y[1])
  c=b-a
  if c>2:
    d+=1
  else:
    d=d  
print(d)      