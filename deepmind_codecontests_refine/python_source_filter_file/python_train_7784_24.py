N, M = map(int, input().split())

for i in range(M):
    j = i // 2
    if i % 2 != 0:
        print(j+1, M-j)
    else:
        print(M+j, 2*M+1-j)
