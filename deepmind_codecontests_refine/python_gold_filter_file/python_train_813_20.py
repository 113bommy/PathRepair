a,b=map(int,input().split())
l=[["."]*(b+2)]+[["."]+list(input())+["."] for _ in range(a)]+[["."]*(b+2)]
for i in range(1,a+1,1):
  for j in range(1,b+1,1):
    if l[i][j]!="#":
      l[i][j]=str(sum(l[x][y]=="#" for x in [i-1,i,i+1] for y in [j-1,j,j+1]))
for i in range(1,a+1,1):
  print("".join(l[i][1:-1]))