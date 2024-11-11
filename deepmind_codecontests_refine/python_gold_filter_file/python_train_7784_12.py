N, M = map(int, input().split())
if N%2:
    for i in range(1, M+1):
        print(i, N-i)
else:
    for i in range(1, M+1):
        if i <= (N//2)//2:
            print(i, N-i+1)
        else:
            print(i+1, N-i+1)
