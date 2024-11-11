N, M = map(int, input().split())

for i in range(M):
    j = i // 2
    if i % 2 == 1:
        print(j+1, M-j)
    else:
        print(M+j+1, 2*M+1-j)

