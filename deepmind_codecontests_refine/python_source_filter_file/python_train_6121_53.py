n=int(input())
l=list(map(int,input().split()))
d=[0]*n
for i,val in enumerate(l):
  d[val-1]=i+1
print(d)
