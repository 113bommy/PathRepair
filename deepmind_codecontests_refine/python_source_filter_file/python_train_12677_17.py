N, M , K = map(int, input().split())
X = [0] + list(map(int, input().split()))
Y = list(map(int, input().split()))
R,sY,j= 0,sum(Y),M
for i in range(N):
    t += X[i]
    if t > K: break
    while j and sY+t > K:
        j-=1
        sY -= Y[j]
    R = max(R, j+i)
print(R)
