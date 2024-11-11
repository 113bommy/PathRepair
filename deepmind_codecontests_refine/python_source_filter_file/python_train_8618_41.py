n,k=map(int,input().split())
h=list(map(int,input().split()))
c=0
for x in h:
  c += x>=h
print(c)