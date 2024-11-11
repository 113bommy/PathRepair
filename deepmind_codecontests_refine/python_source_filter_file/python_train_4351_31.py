
A = [list(map(int, input().split(' '))) for  _ in range(3)]
N = int(input())
B = set([int(input()) for _ in range(N)])

X = []
X += [set(A[i]) for i in range(3)]
X += [set([A[j][i] for j in range(3)]) for i in range(3)]
X += [set([A[0][2], A[1][1], A[2][0]]), set([A[2][2], A[1][1], A[0][0]])]

for x in X:
    if x in B:
        print('Yes')
        break
else:
    print('No')