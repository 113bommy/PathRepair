def e(x,y):
 A[y][x]='0'
 for t in range(-3,4):
  if 0<=x+dx<8 and A[y][x+dx]=='1':e(x+dx,y)
  if 0<=y+dy<8 and A[y+dy][x]=='1':e(x,y+dy)

for i in range(int(input())):
 print(f'Data {i+1}:')
 input()
 A=[list(input())for _ in[0]*8]
 e(int(input())-1,int(input())-1)
 for r in A:print(*r,sep='')
