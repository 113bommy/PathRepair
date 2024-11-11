n,k=map(int,input().split())
x= list(map(int,input().split()))
c=0
p=x[k-1]
for i in x:
    if i>p and i>0:
        c=c+1

print(c)