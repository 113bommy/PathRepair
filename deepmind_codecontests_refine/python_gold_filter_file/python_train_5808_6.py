N, A, B, C = map(int, input().split())
S = [input() for _ in range(N)]

A, B, C = min(A, 2), min(B, 2), min(C, 2)
X = [0, A, B, C]  # 1-indexecの方が楽そう
F = {1: 'A', 2: 'B', 3: 'C'}

ans = []
for k, s in enumerate(S):
    if s == 'AB':
        i, j = 1, 2
    elif s == 'BC':
        i, j = 2, 3
    elif s == 'AC':
        i, j = 1, 3

    if X[i] > X[j]:
        X[i] -= 1
        X[j] += 1
        ans.append(j)

    elif X[i] < X[j]:
        X[i] += 1
        X[j] -= 1
        ans.append(i)

    else:
        if (X[i] == X[j] == 1) and (k < N - 1):
            if ((S[k + 1][0] == F[i]) and (S[k + 1][1] == F[i ^ j])) or ((S[k + 1][0] == F[i ^ j]) and (S[k + 1][1] == F[i])):
                X[i] += 1
                X[j] -= 1
                ans.append(i)
            else:
                X[j] += 1
                X[i] -= 1
                ans.append(j)
        else:
            X[i] -= 1
            X[j] += 1
            ans.append(j)

    if any([x < 0 for x in X]):
        print('No')
        exit()

print('Yes')
for a in ans:
    print(F[a])
