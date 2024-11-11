n, a, b, c = map(int, input().split())
A = [a, b, c]
D = {'AB': 0, 'BC': 1, 'AC': 2}
S = [input() for i in range(n)]
S.append('AB')
X = []
for i in range(n):
    x, y = D[S[i]], (D[S[i]] + 1) % 3
    if A[x] == 0 and A[y] == 0:
        print('No')
        exit()
    if A[x] < A[y]:
        A[x], A[y] = A[x] + 1, A[y] - 1
        X.append('ABC'[x])
    elif A[x] > A[y]:
        A[x], A[y] = A[x] - 1, A[y] + 1
        X.append('ABC'[y])
    else:
        x1, y1 = D[S[i + 1]], (D[S[i + 1]] + 1) % 3
        if x == y1:
            A[x], A[y] = A[x] + 1, A[y] - 1
            X.append('ABC'[x])
        else:
            A[x], A[y] = A[x] - 1, A[y] + 1
            X.append('ABC'[y])
print('Yes')
print(*X, sep='\n')
