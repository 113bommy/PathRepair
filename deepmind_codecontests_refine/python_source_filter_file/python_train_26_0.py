r1,r2=map(int,input().split())
c1,c2=map(int,input().split())
d1,d2=map(int,input().split())
a=[[0,0],[0,0]]

def debug(x):
    for i in range(2):
        for j in range(2):
            print(a[i][j],end=" ")
        print()

def valid():
    if a[0][0]+a[1][1]==d1 and a[0][1]+a[1][0]==d2:
        for i in range(2):
            for j in range(2):
                if a[i][j] in range(1,10):
                    return False

        return True
    return False
for i in range(1,10):
    a[0][0]=i
    a[0][1]=r1-a[0][0]
    a[1][0]=c1-a[0][0]
    a[1][1]=r2-a[1][0]
    l=[]
    for i in range(2):
        for j in range(2):
            l.append(a[i][j])
    l=set(l)
    if len(l)==4 and valid():
        debug(a)
        break
else:
    print(-1)