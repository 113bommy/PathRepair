n=int(input())
ans=0
p=2

while p<=10**6 and n!=1:
  dv=0
  wa=1
  num=1
  while n%p==0:
    n/=p
    n=int(n)
    dv+=1
  if dv>0:
    while dv>=wa:
      num+=1
      wa+=num
    num-=1
    ans+=num
  p+=1
  
if n!=1:
  print("1")
  exit()
  
print(str(ans))