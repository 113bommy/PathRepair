t=int(input(''))
n= list(map(int, input().split()))
n.sort()
k=(n[(2*t)-1]-n[t])*(n[t-1]-n[0])
for i in range(1,t):
  ans=min((n[i+t]-n[i])*(n[(2*t)-1]-n[0]),k)
print(ans)