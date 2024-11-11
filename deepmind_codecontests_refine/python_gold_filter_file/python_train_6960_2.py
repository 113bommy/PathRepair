W,H,N=map(int,input().split(' '))
info = [[0],[W],[0],[H]] #min_x,max_x,min_y,max_y
for i in range(N):
  x,y,a=map(int,input().split(' '))
  info[a-1].append([x,y][(a-1)//2])
print(max(min(info[1])-max(info[0]),0)*max(min(info[3])-max(info[2]),0))