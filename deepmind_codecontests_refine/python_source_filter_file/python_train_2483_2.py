a,b=map(int,input().split())
l=[list(map(int,input().split())) for _ in range(b)]
for i in range(1,a+1):
  print(sum(1 for i in l if i[0]==i or i[1]==i))