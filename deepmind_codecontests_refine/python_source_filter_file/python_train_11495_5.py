n=int(input())
line=[int(x) for x in input().split()]
bill=[0,0,0]
if line[0] != 25:
    print('NO')
else:
    judge=True
    for i in line:
        if i==25:
            bill[0]+=1
        elif i==50:
            bill[0]-=1
            bill[1]+=1
            if bill[0]<0:
                print('NO')
                judge=False
                break
        else:
            bill[2]+=1
            left=100-50*min(1,bill[1])
            bill[1]-=min(1,bill[1])
            bill[0]-=left//25
            if bill[0]<0:
                print('NO')
                judge=False
                break
    if judge==True:
        print('YES')
