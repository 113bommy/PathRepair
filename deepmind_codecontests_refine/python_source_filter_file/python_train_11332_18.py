N,M=map(int, input().split())
A=[input() for _ in range(N)]
B=[input() for _ in range(M)]

for i in range(N-M+1):
    for j in range(N-M+1):
        t=[k[j:j*m] for k in a[i:i+m]]
        if t==B:
            print('Yes')
            exit()
print('No')
