U,R,D,L="URDL"
d={i:[]for i in"URDL"}
_,*a=map(str.split,open(0))
for*z,u in a:d[u]+=[*map(int,z)],
N,P,M=9e9,"x+y,","x-y,"
for*F,S in(D,U,"x,y,"),(L,R,"y,x,"),(U,R,P+M),(L,D,P+M),(L,U,M+P),(D,R,M+P):
 n=p=-9e9
 for x,y,r in sorted(eval(f"[({S}Q)for Q,P in enumerate(F)for x,y in d[P]]")):
  if r:n,p=x,y
  elif x==n:N=min(N,(y-p)*5)
print(["SAFE",N*5][N<9e9])