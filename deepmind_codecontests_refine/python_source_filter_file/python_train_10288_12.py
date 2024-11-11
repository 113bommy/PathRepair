n=int(input())
hoge=[]
for i in range(n):
  x,y,z=map(int,input().split())
  if(z!=0):
    hoge.append([x,y,z])
  

if(len(hoge)==1):
  print(*hoge[0])
  exit()

for i in range(101):
  for j in range(101):
    h=[]
    for k in range(n):
      h.append(hoge[k][2]+abs(hoge[k][0]-i)+abs(hoge[k][1]-j))
      
    if(h.count(h[0])==len(h)):
      print(i,j,h[0])