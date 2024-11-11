L = int(input().strip())
for _ in range(0,L):
    gx,gy = map(int,input().strip().split(" "))
    heiankyo = [[0 for j in range(0,gx+1)] for i in range(0,gy+1)]
    heiankyo[0][0] = 1
    P = int(input())
    matatabi = []
    for p in range(P):
        x1,y1,x2,y2 = map(int,input().strip().split(" "))
        l = [[x1,y1],[x2,y2]]    
        l.sort()
        matatabi.append(l)
    for i in range(1,gy+1):
        if not [[i-1,0],[i,0]] in matatabi:
            heiankyo[i][0] = heiankyo[i-1][0]
    for j in range(1,gx+1):
        if not [[0,j-1],[0,j]] in matatabi:
            heiankyo[0][j] = heiankyo[0][j-1]
    for i in range(1,gy+1):
        for j in range(1,gx+1):
            if not [[i-1,j],[i,j]] in matatabi:
                heiankyo[i][j] = heiankyo[i][j] + heiankyo[i-1][j]
            if not [[i,j-1],[i,j]] in matatabi:
                heiankyo[i][j] = heiankyo[i][j] + heiankyo[i][j-1]
    if heiankyo[gy][gx] == 0:
        print("Miserable Hokusai!")
    else:
        print(heiankyo[gy][gx])
