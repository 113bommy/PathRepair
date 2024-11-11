N,M=map(int,input().split())

if N%2==1:
    S=1
    L=N
    for i in range(M):
        print(S+i,L-i)
else:
    S=1
    L=N
    for i in range(M):
        if S+i>=N/4:
            print(S+i,L-i-1)
        else:
            print(S+i,L-i)