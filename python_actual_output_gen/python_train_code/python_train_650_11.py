N,D=map(int, input().split())
a=0
for i in str(N):
  x,y=map(int, input().split())
  if x*x+y*y<=D*D:
    a+=1
  else:
    pass
print(a)
