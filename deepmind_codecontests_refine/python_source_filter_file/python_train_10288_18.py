N=int(input())
A=[list(map(int,input().split())) for i in range(N)]
B=sorted(A,key=lambda x: x[2])

#(i,j)が中心座標にあるとき
for i in range(101):
  for j in range(101):
    H=abs(B[0][0]-i)+abs(B[0][1]-j)+B[0][2]
    for k in range(N):
      if max(H-abs(B[k][0]-i)-abs(B[k][1]-j),0)!=B[k][2]:
        break
    else:
      print(i,j,H)     
      exit()