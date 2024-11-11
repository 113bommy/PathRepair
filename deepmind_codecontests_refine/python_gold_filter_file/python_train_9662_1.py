N=int(input())
h=[0]+list(map(int,input().split()))
c=0
for i in range(N):
  c+=max(h[i+1]-h[i],0)
print(c)