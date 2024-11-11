
n=int(input())
b=list(map(int,input().split()))
if n<3:
    print(0)

else:
    mifow=[0]
    mafow=[0]
    m=b[0]
    ma=b[0]
    for j in range(1,n):
        if b[j]<m:
            m=b[j]
            mifow.append(j)

        else:
            mifow.append(mifow[-1])

        if b[j] > ma:
            ma = b[j]
            mafow.append(j)

        else:
            mafow.append(mafow[-1])

    mibw = [n-1]
    mabw = [n-1]
    m = b[-1]
    ma = b[-1]
    for j in range(1, n):
        if b[n-1-j] < m:
            m = b[n-1-j]
            mibw.append(n-1-j)

        else:
            mibw.append(mibw[-1])

        if b[n-1-j] > ma:
            ma = b[n-1-j]
            mabw.append(n-1-j)

        else:
            mabw.append(mabw[-1])

    mibw.reverse()
    mabw.reverse()


    poss=0
    for j in range(1,n-1):
        m1=mifow[j]
        m2=mibw[j]
        if m1==j or m2==j:
            pass
        else:
            ind=[m1+1,j+1,m2+1]
            poss=1
            break
        m1=mafow[j]
        m2=mabw[j]
        if m1 == j or m2 == j:
            pass
        else:
            ind = [m1 + 1, j + 1, m2 + 1]
            poss = 1
            break

    if poss:
        print(3)
        print(*ind)

    else:
        print(0)






