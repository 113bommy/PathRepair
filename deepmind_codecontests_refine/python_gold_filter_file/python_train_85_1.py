n,m=map(int,input().split())
a=[list(map(int,input().split())) for i in range(n)]
b=[list(map(int,input().split())) for i in range(m)]
for i in a:
  cnt=2*(10**16)
  ans=0
  for j in range(len(b)):
    if abs(i[0]-b[j][0])+ abs(i[1]-b[j][1])<cnt:
      cnt=abs(i[0]-b[j][0])+ abs(i[1]-b[j][1])
      ans=j+1
  print(ans)
