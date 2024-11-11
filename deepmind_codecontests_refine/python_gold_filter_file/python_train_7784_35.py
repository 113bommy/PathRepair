N,M = map(int,input().split())

if N % 2 == 1:
    for i in range(M):
        print(i+1,N-i)
else: #こっちに問題あり
    for i in range(M):
        if i<N//4:
            print(i+1,N-i)
        else:
            print(i+1,N-i-1)