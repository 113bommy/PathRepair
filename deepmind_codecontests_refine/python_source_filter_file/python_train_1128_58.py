N=int(input())
a=list(map(int, input().split()))
c=[0]*9
for i in range(N):
  c[min(a[i]//400, 8)]+=1
  
temp=[1 for i in range(8) if c[i]>0]
x=len(temp)
y=min(8, x+c[8])

print(max(x, 1), y)