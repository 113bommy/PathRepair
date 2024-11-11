N=int(input())
R=sorted([list(map(int,input().split())) for i in range(N)],key=lambda x:x[0])
B=sorted([list(map(int,input().split())) for i in range(N)],key=lambda x:x[0])
U=[0]*N

for c,d in B:
  i,mv,mi=0,-1,0
  for a,b in R:
    if a<c:
      if b<d and U[i]==0:
        if mv<b:
          mv,mi=b,i
      i+=1
    else:
      break

  if mv!=-1:
    U[mi]=1

print(sum(U))
