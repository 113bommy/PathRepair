n,k=map(int,input().split())
abilities=sorted(list(map(int,input().split())))
foods=sorted(list(map(int,input().split())),reverse=True)

if sum(abilities)<=k:
  print(0)
  exit()
  
def check(score):
  ret=0
  for a,f in zip(abilities,foods):
    ret+=(a*f-score+f-1)//f
  return ret<=k

ok=10**12
ng=0
for _ in range(50):
  mid=(ok+ng)//2
  if check(mid):
    ok=mid
  else:
    ng=mid
print(ok)
  
       
