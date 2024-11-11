n,p=map(int,input().split())
if n==1:
    print(p)
    exit()
a=1
for i in range(2,int(p**0.5)+2):
  if p%i==0:
    c=0
    while p%i==0:
      p//=i
      c+=1
    a*=max((c//n)*i,1)
  if p==1:
    break
print(a)