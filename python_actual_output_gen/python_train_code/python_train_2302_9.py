N = int(input())
M = float('inf')
for i in range(N):
    M = min(M,sum(list(map(int,str(i)))+list(map(int,str(N-i)))))
print(M)