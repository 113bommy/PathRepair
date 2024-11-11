import sys
readline = sys.stdin.readline

def obt(i, j, k):
    x1, y1 = Points[i][0], Points[i][1]
    x2, y2 = Points[j][0], Points[j][1]
    x3, y3 = Points[k][0], Points[k][1]
    
    
    X21, Y21 = x1-x2, y1-y2
    X23, Y23 = x3-x2, y3-y2
    return (X21*X23 + Y21*Y23) <= 0
N = int(readline())
Points = [tuple(map(int, readline().split())) for _ in range(N)]

L = [0, 1]
for i in range(2, N):
    L.append(i)
    if obt(L[i-2], L[i-1], L[i]):
        L[i], L[i-1] = L[i-1], L[i]
    for j in range(i-1, 1, -1):
        if obt(L[j-2], L[j-1], L[j]):
            L[j-1], L[j] = L[j], L[j-1]
        else:
            break


print(*[i+1 for i in L])