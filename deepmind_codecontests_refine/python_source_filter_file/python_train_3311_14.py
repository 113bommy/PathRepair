R,G,B,N=map(int,input().split())
 
ans=0
for r in range(N//R+1):
  for g in range(N//G+1):
    if R*r+G*g>N: continue
    if (N-R*r-G*g)%B!=0: continue
    ans+=1
print(ans)