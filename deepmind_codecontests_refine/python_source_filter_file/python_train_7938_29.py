
n,m,y,x=map(int,input().split())

print(x,y)
for i in range(1,x):
    print(y,i)
for i in range(x+1,m+1):
    print(y,i)

for i in range(1,y):
    if i%2==1:
        for j in range(m,0,-1):
            print(i,j)
    else:
        for j in range(1,m+1):
            print(i,j)

for i in range(y+1,n+1):
    if i%2==0:
        for j in range(m,0,-1):
            print(i,j)
    else:
        for j in range(1,m+1):
            print(i,j)



