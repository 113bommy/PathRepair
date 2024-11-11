N = int(input())
XY = [list(map(int,input().split())) for _ in range(N)]

if N==1:
    print(0)
    exit()

dis = {}

for i in range(N):
    for j in range(N):
        if i == j:
            continue
        X = XY[j][0]-XY[i][0]
        Y = XY[j][1]-XY[i][1]
        if (X,Y) in dis:
            dis[(X,Y)] += 1
        else:
            dis[(X,Y)] = 1
print(N-max(dis.values()))