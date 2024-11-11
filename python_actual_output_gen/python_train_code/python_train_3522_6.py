a = [[1,1,1],[1,1,1],[1,1,1]]
for i in range(3):
    l = list(map(int,input().split()))
    for j in range(3):
        if(l[j]%2==1):
            a[i][j] = 1 - a[i][j]
            if((j-1)>0):
                a[i][j-1]= 1 - a[i][j-1]
            if((j+1)<3):
                a[i][j+1]= 1 - a[i][j+1]
            if(i-1 > 0):
                a[i-1][j]= 1 - a[i-1][j]
            if(i+1 < 3):
                a[i+1][j]= 1 - a[i+1][j]

for i in range(3):
    for j in range(3):
        a[i][j] = str(a[i][j])
    print("".join(a[i]))
