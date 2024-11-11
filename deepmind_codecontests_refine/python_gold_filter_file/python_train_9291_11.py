t=int(input())
for i in range(t):
    n,k=list(map(int,input().split()))
    matrix=[[0]*n for j in range(n)]
    a=k//n
    b=k%n
    for j in range(a):
        for l in range(n):
            matrix[(j+l)%n][l%n]=1
    for j in range(b):
        matrix[(a+j)%n][j%n]=1
    if b==0:
        print(0)
        for j in range(n):
            print("".join(str(x) for x in matrix[j]))
    else:
        print(2)
        for j in range(n):
            print("".join(str(x) for x in matrix[j]))