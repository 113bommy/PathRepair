for _ in range(int(input())):
    n = int(input())
    A = list(map(int,input().split()))
    B = [0]*n
    for i in range(1,n,2):
        B[i-1],B[i] = -A[i],A[1-i]
        
    print(*B)