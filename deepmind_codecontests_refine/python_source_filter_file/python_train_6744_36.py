n,*a,=map(int,open(0).read().split())
d=[0]*n
for i in a:
  d[i-1]+=1
print(*d[1:],sep="\n")  