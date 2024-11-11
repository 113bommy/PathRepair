N, K = [int(_) for _ in input().split()]
S = input()
O = [[0, 0]]
is1 = False
for i in range(N):
    if S[i] == '1':
        if not is1:
            O += [[i, N]]
        is1 = True
    elif S[i] == '0':
        if is1:
            O[-1][-1] = i
        is1 = False
O += [[N, N]]
K = min([len(O) - 1, K])
ans = 0
for i in range(len(O) - K):
    ans = max([ans, O[i + K][1] - O[i][0]])
print(ans)
