N,M=map(int,input().split())
A=[input()for _ in[0]*N]
B=[input()for _ in[0]*M]
for i in range(N-M):
    for j in range(N-M):
        for k in range(M):
            if A[i+k][j:j+M]!=B[k]:
                break
        else:
            print('Yes');exit()
print('No')