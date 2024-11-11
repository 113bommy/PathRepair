N,M =list(map(int,input().split()))
la=1
rm=N
for i in range(M):
  a,b=list(map(int,input().split()))
  la=max(la,a)
  rm=min(rm,b)
print(max(0,la-rm+1))

