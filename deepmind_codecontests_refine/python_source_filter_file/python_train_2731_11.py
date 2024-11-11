t=int(input())
for i in range(t):
    a=[]
    x=[0,9,8,7,6,5,4,3,2,1]
    for j in range(9):
        b=input()
        a.append(list(map(int,list(b))))
    a[0][0]=x[a[0][0]]
    a[1][4]=x[a[1][4]]
    a[2][8]=x[a[2][8]]
    a[3][1]=x[a[3][1]]
    a[4][5]=x[a[4][5]]
    a[5][6]=x[a[5][6]]
    a[6][2]=x[a[6][2]]
    a[7][3]=x[a[7][3]]
    a[8][7]=x[a[8][7]]
    for j in range(9):
        print(''.join(map(str,a[j])))