

n,m,x,y = list(map(int,input().split()))
x-=1
y-=1
x,y = y,x
fx = x
fy = y

# deb = []
# for i in range(n):
#     deb.append([0]*m)

def printd(xi,yi):
    print(yi,xi)
    # deb[yi-1][xi-1] +=1
printd(x+1,y+1)

for i in range(x):
    printd(i+1,y+1)
for i in range(x+1,m):
    printd(i+1,y+1)
fl = True
for i in range(y):
    for g in range(m):
        if fl:
            printd(m-g,i+1)
        else:
            printd(g+1,i+1)
    fl = not fl
for i in range(y+1,n):
    for g in range(m):
        if fl:
            printd(m-g,i+1)
        else:
            printd(g+1,i+1)
    fl = not fl
# for i in range(n):
#     print(*deb[i])