import math

N=int(input())

PI = math.pi

X=[]
Y=[]
for i in range(N):
    x,y=[int(i) for i in input().split()]
    X.append(x)
    Y.append(y)

for i in range(N):
    kakudo = [math.atan2(Y[i]-Y[j],X[i]-X[j]) for j in range(N) if j != i]
    kakudo.sort()
    print(kakudo)
    kmax = 0
    if N == 2:
        kmax = 2*PI
    else:
        for j in range(N-2):
            kmax = max(kmax,kakudo[j+1] - kakudo[j])
            kmax = max(kmax, kakudo[0] + 2*PI - kakudo[N-2])
    print(max(0,kmax-PI)/(2*PI))

#print(math.atan2(0,0))