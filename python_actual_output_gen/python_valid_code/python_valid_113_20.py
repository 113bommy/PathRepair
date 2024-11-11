N=int(input())
h=list(map(int,input().split()))

c=[0]*N
c[1]=abs(h[1]-h[0])
for i in range(2,N):
  c[i]=min(c[i-2]+abs(h[i]-h[i-2]),c[i-1]+abs(h[i]-h[i-1]))
print(c)