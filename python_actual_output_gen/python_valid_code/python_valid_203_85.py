for _ in range(int(input())):
    N,M=map(int,input().split())
    if N<M:
        print(M)
    elif N==2:
        print(M)
    else:
        print(M+M)
