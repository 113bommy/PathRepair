def searchmat(a):
    for i in range(5):
        for j in range(5):
            if a[i][j]==1:
                return i,j
    pass
    
a=[]
moves=0
for i in range(5):
    a.append(list(map(int,input().split(" "))))
i,j=searchmat(a)
moves=abs(i-2)+abs(j-2)
print(moves)