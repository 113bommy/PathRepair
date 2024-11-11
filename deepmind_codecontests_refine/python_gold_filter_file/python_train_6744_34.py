n,*a,=map(int,open(0).read().split())
b=[0]*n
for i in a:
    b[i-1]+=1
print(*b,sep="\n")  