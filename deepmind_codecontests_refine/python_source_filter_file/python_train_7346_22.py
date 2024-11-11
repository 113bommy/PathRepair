n=int(input())
i=1
r=[]
while i<=n:
  r+=[i]
  n-=i
  i+=1
print(f'{len(r)}\n{" ".join(map(str,r))}')