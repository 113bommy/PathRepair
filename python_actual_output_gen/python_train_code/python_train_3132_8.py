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
M = T.bit_length()+1
if D > X[0]:
    print(-1)
    sys.exit()
Y = 0
for i in range(M, -1, -1):
    if T & (1<<i) and ((1<<i)|Y)^D <= X[0]:
        Y = (1<<i)|Y
if Y == 0:
    print(-1)
else:
    print(X[0]-(Y^D))
