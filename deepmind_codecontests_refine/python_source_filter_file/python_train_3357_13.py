t=int(input())
for y in range(t):
    lst0=list(map(int,input().split()))
    n,k=lst0[0],lst0[1]
    ge=k//(n-1)
    sheng=k%(n-1)
    if n==2:
        print(ge*n+sheng-1)
    else:
        print(ge*n+sheng)
