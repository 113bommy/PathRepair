# import numpy as np

def findStar(ar,i,j,n,m):
    size = 1
    newStars = 0
    while True:
        if j-size>-1 and j+size<m and i-size>-1 and i+size<n and ar[i][j-size]>0 and ar[i][j+size]>0 and ar[i-size][j]>0 and ar[i+size][j]>0:

            if ar[i][j-size]==1:
                newStars+=1
            ar[i][j-size]+=1

            if ar[i][j+size]==1:
                newStars+=1
            ar[i][j+size]+=1

            if ar[i-size][j]==1:
                newStars+=1
            ar[i-size][j]+=1

            if ar[i+size][j]==1:
                newStars+=1
            ar[i+size][j]+=1

            if ar[i][j] == 1:
                newStars+=1
            ar[i][j] += 1

            size+=1

            # print(np.array(ar))
            # print()
        else:
            return ar,size-1,newStars

n,m = map(int,input().split())
mat = []
ar = []
for _ in range(n):
    l = list(input())
    mat.append(l)
    ar.append([0]*m)
# print(ar)
starCount = 0
for i in range(n):
    for j in range(m):
        if mat[i][j]=='*':
            ar[i][j] = 1
            starCount+=1

# print(np.array(ar)) #np
# print()
out = []
countStars = 0
for i in range(1,n-1):
    for j in range(1,m-1):
        if ar[i][j]>0:
            ar,vals,newStars = findStar(ar,i,j,n,m)
            if vals>0:
                out.append([i+1,j+1,vals])
                countStars += newStars
                # print("New Stars :",str(newStars))

if starCount == countStars:
    print(len(out))
    for row in out:
        print(row[0],row[1],row[2])
else:
    print(-1)