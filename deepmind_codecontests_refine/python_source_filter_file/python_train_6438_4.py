N, M = map(int, input().split())
from_1 = [False]*N
to_N = [False]*N
for _ in range(M):
    a, b = map(int, input().split())
    if a-1 == 0:
        from_1[b-1] = True
    elif b-1 == 0:
        to_N[a-1] = True
for i in range(1, N):
    if from_1[i] and to_N[i]:
        print('POSSIBLE')
        break
else:
    print('IMPOSSIBLE')