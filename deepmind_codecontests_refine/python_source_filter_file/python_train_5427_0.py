n = int(input())
parents = list(map(int, input().split(' ')))
S = list(map(int, input().split(' ')))

children = [[] for i in range(n)]
for i, parent in enumerate(parents):
    children[parent-1].append(i+2)

A = S[:]
for i in range(1, len(A)):
    if A[i] != -1:
        A[i] -= A[parents[parents[i-1]-2]-1]
        if A[i] < 0:
            print(-1)
            exit(0)

for i in range(1, len(A)):
    if A[i] == -1:
        if len(children[i]) == 0:
            A[i] = 0
        else:
            A[i] = min([A[j-1] for j in children[i]])
        for j in children[i]:
            A[j-1] -= A[i]

print(sum(A))