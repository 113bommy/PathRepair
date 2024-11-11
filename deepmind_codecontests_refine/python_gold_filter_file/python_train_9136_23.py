import sys
N, = map(int, input().split())
X = list(map(int, input().split()))
S = X[0]+X[1]
T = 0
for i in range(2, N):
    T ^= X[i]
if S<T or (S-T)%2:
    print(-1)
    sys.exit()

D = (S-T)//2
if D&T:
    print(-1)
    sys.exit()

Y = D
for i in range(T.bit_length()+1, -1, -1):
    if T&(1<<i)|Y <= X[0]:
        Y |= T&(1<<i)
if 0<Y<=X[0]:
    print(X[0]-Y)
else:
    print(-1)
