N, M = map(int, input().split())

A = set({})
B = set({})
for j in range(N-1):
    tmp = []
    tmp = [int(i) for i in input().split()]
    if tmp[0] == 1:
        A.add(tmp[1])
    elif tmp[1] == N:
        B.add(tmp[0])

if len(A.intersection(B)) > 0:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
