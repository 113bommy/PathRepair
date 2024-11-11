n=int(input())
a=list(map(int,input().split()))
c2=0
c4=0
for aa in a:
  if aa%2 == 0:
    if aa%4 == 0:
      c4+=1
    else:
      c2+=1
c0=n-(c2+c4)
cc=c4-c0
if c2>=1 and c2 != n:
  cc-=1
print("Yes" if cc >= -1 else "No")
