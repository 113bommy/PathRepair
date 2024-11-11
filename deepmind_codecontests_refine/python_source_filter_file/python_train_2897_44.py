# B
N = int(input())
S_list = list()
for _ in range(N):
    S_list.append(list(input()))

res = 0

def is_symmetric(M):
    res = True
    for i in range(N):
        for j in range(i+i, N):
            if M[i][j] != M[j][i]:
                return False
    return True

for _ in range(N):
    if is_symmetric(S_list):
        res += 1
    for i in range(N):
        S_list[i] = S_list[i][1:] + S_list[i][:1]
    
print(res*N)