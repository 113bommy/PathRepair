N,C,K=map(int,input().split())
TT=[int(input()) for _ in range(N)]
TT.sort()

B=0
L=0
ans=0
for T in TT:
  if B==0:
    L=T+K
    B=C-1
    ans+=1
  else:
    if L>T:
      B-=1
    else:
      L=T+K
      B=C-1
      ans+=1
  #print(T,B,L)
print(ans)