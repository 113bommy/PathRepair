n=int(input())
XYH=[]
for i in range(n):
  x,y,h=map(int,input().split())
  XYH.append([x,y,h])
XYH.sort(key=lambda x:x[2])
for i in range(101):
  for j in range(101):
    peak=abs(i-XYH[0][0])+abs(j-XYH[0][1])+XYH[0][2]
    flag=1
    for k in range(1,n):
      if max(0,peak-abs(i-XYH[k][0])-abs(j-XYH[k][1]))!=XYH[k][2]:
        flag=0
    if flag==1:
      Ans=[i,j,peak]
print(*Ans)