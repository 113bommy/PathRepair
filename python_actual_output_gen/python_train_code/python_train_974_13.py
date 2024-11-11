N=int(input())
d=list(map(int,input().split()))
s=0
for i in range(d):
  s+=d[i]*sum(d[i+1:N+1])
print(s)
