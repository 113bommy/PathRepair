#直径が答えになるわけではない

N = int(input())
S = [list(map(int, input())) for _ in range(N)]

# for s in S:
#     print (s)

lst = [0] * N
lst[0] = 1

stack = [0]
flag = True
while len(stack) != 0:
    tmp = stack.pop()
    for index, x in enumerate(S[tmp]):
        if x == 0:
            continue
        if lst[index] == 0:
            lst[index] = -lst[tmp]
            stack.append(index)
        else:
            if lst[tmp] == -lst[index]:
                pass
            else:
                flag = False
                break
    if not flag:
        print (-1)
        exit()

INF = 10 ** 9
for i in range(N):
    for j in range(N):
        if S[i][j] == 0 and i != j:
            S[i][j] = INF

for k in range(N):
    for i in range(N):
        for j in range(N):
            S[i][j] = min(S[i][j], S[i][k] + S[k][j])
            
ans = 0
for i in range(N):
    for j in range(N):
        ans = max(S[i][j], ans)

print (ans + 1)