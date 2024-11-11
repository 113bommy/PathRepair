n,x,y=map(int,input().split())
x-=1; y-=1
C=[0]*(n-1)

for i in range(n):
  for j in range(i+1,n):
    d=min(j-i,abs(x-i)+abs(y-j)+1)
    C[d]+=1

print(*C)