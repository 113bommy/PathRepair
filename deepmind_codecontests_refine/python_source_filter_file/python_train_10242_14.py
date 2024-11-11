ar=[]
ar2=[]
a=0
for i in range(0,3):
    ar.append(list(map(int,input().rstrip().split())))
for i in range(0,3):
    for j in range(0,3):
        if i==0 and j==0:
            if (ar[i][j]+ar[i+1][j]+ar[i][j+1])%2==0:
                ar2.append(1)
            else:
                ar2.append(0)
        elif 0<i<2 and j==0:
            if (ar[i][j]+ar[i+1][j]+ar[i][j+1]+ar[i-1][j])%2==0:
                ar2.append(1)
            else:
                ar2.append(0)
        elif i==0 and 0<j<2:
            if (ar[i][j] + ar[i+1][j] + ar[i][j+1] + ar[i][j-1]) % 2 == 0:
                ar2.append(1)
            else:
                ar2.append(0)
        elif 0<i<2 and 0<j<2:
            if (ar[i][j]+ar[i+1][j]+ar[i][j+1]+ar[i-1][j]+ar[i][j-1])%2==0:
                ar2.append(1)
            else:
                ar2.append(0)
        elif i==2 and j==2:
            if (ar[i][j]+ar[i-1][j]+ar[i][j-1])%2==0:
                ar2.append(1)
            else:
                ar2.append(0)
        elif 0<i<2 and j==2:
            if (ar[i][j]+ar[i+1][j]+ar[i-1][j]+ar[i][j-1])%2==0:
                ar2.append(1)
            else:
                ar2.append(0)
        elif i==2 and 0<j<2:
            if (ar[i][j]+ar[i][j+1]+ar[i-1][j]+ar[i][j-1])%2==0:
                ar2.append(1)
            else:
                ar2.append(0)
        elif 0<i<2 and 0<j<2:
            if (ar[i][j]+ar[i+1][j]+ar[i][j+1]+ar[i-1][j]+ar[i][j-1])%2==0:
                ar2.append(1)
            else:
                ar2.append(0)
        elif  i==0 and j==2:
            if (ar[i][j] + ar[i + 1][j] + ar[i][j - 1]) % 2 == 0:
                ar2.append(1)
            else:
                ar2.append(0)
        elif i==2 and j==0:
            if (ar[i][j]+ ar[i][j + 1] + ar[i - 1][j]) % 2 == 0:
                ar2.append(1)
            else:
                ar2.append(0)

for i in range(0,3):
    for j in range(0,3):
        if j==2:
            print(ar2[a],"\n")
            a=a+1
        elif j<3:
            print(ar2[a],end=" ")
            a = a + 1







