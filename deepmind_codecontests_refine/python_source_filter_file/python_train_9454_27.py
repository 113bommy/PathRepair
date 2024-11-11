N = int(input())
M = 1
while M*(M+1)//2 < N:
    M += 1
if M*(M+1)//2 != N:
    print('No')
    exit()
M += 1
S = [[] for i in range(M)]
k = 1
print('Yes')
print(M)
for i in range(M):
    for j in range(i+1, M):
        S[i].append(k)
        S[j].append(k)
        k += 1
for i in range(M):
    print(M, *S[i])