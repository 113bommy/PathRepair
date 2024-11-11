lights=[[1,1,1],[1,1,1],[1,1,1]]
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
given=[]
given.append(a)
given.append(b)
given.append(c)
def change(i,j):
    if(lights[i][j]==1):
        lights[i][j]=0
    else:
        lights[i][j]=1
for i in range(3):
    for j in range(3):
        if(i==0 and j==0):
            if(given[i][j]%2!=0):
                change(i,j)
                change(i+1,j)
                change(i,j+1)
        if(i==0 and j==1):
            if(given[i][j]%2!=0):
                change(i,j)
                change(i+1,j)
                change(i,j-1)
                change(i,j+1)
        if(i==0 and j==2):
            if(given[i][j]%2!=0):
                change(i,j)
                change(i+1,j)
                change(i,j-1)
        if(i==1 and j==0):
            if(given[i][j]%2!=0):
                change(i,j)
                change(i+1,j)
                change(i,j+1)
                change(i+1,j)
        if(i==1 and j==1):
            if(given[i][j]%2!=0):
                change(i,j)
                change(i-1,j)
                change(i+1,j)
                change(i,j-1)
                change(i,j+1)
        if(i==1 and j==2):
            if(given[i][j]%2!=0):
                change(i,j)
                change(i-1,j)
                change(i+1,j)
                change(i,j-1)
        if(i==2 and j==0):
            if(given[i][j]%2!=0):
                change(i,j)
                change(i-1,j)
                change(i,j+1)
        if(i==2 and j==1):
            if(given[i][j]%2!=0):
                change(i,j)
                change(i-1,j)
                change(i,j-1)
                change(i,j+1)
        if(i==2 and j==2):
            if(given[i][j]%2!=0):
                change(i,j)
                change(i-1,j)
                change(i,j-1)
for i in range(len(lights)):
    c=lights[i]
    a=""
    for j in range(len(c)):
        a+=str(c[j])
    print(a)
