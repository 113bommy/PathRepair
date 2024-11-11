Q,H,S,D = map(int,input().split())
N = int(input())
A = min(Q*4,H*2,S)
if 2*A <= D:
    print(N*A)
else:
    print(N//2*D + A)
