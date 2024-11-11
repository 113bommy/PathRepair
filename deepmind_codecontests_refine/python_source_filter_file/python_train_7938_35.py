r,c,xi,yi=list(map(int,input().split()))
print(xi,yi)
for m in range(1,yi):
    print(xi,m)
for n in range(yi+1,c+1):
    print(xi,n)
y=c
for i in range(1,xi):
    if y==c:
        for j in range(c,0,-1):
            print(i,j)
        y=1
        continue
    if y==1:
        for j in range(1,c+1):
            print(i,j)
        y=c
for p in range(xi+1,r+1):
    if y==c:
        for q in range(c,0,-1):
            print(p,q)
        y==1
        continue
    if y==1:
        for q in range(1,c+1):
            print(p,q) 
        y==c

