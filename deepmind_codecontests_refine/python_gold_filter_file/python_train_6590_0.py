import sys
input = sys.stdin.readline

t=int(input())

for tests in range(t):
    n,m=map(int,input().split())
    MAP=[list(input().strip()) for i in range(n)]

    if m<=1:
        for i in range(n):
            MAP[i][0]="X"

    for j in range(1,m,3):
        for i in range(n):
            MAP[i][j]="X"

    for j in range(2,m,3):

        if j+1<m:
                    
            for i in range(n):
                if MAP[i][j]=="X":
                    MAP[i][j+1]="X"
                    break

            else:
                for i in range(n):
                    if MAP[i][j+1]=="X":
                        MAP[i][j]="X"
                        break

                else:
                    MAP[0][j]=MAP[0][j+1]="X"

    if m%3==1:
        for i in range(n):
            if MAP[i][m-1]=="X":
                MAP[i][m-2]="X"
        
    for i in range(n):
        print("".join(MAP[i]))

    #print()
            

    
