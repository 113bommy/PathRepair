N=int(input())
for _ in range(N):
    C=int(input())
    L=list()
    L.append(input())
    L.append(input())

    flag=0
    print(L)
    for i in range(C-1):
        if L[0][i+1]=='1' and L[1][i+1] =='1':
            flag=1
            break
    if flag==1:
        print("NO")
    else:
        print("YES")
