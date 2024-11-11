def solve(M, N): 
    tileArea = 2*1 
    boardArea = M*N 
    print(boardArea/tileArea)
M,N=map(int,input().split())
solve(M,N)