n,k=map(int,input().split())
l=list(map(int,input().split()))
c=0
s=l[k-1]
for i in l:
    if i>=s and i!=0:
        c=c+1

print(c)