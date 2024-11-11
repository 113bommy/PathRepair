N, M = map(int, input().split())

if(2*N <= M):
    m = M-2*N
    print(N+m//4)
else:
    print(m//2)