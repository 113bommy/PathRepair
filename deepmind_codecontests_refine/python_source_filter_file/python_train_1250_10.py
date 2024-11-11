def partition(A, p, r):
    x = A[r]
    i = p-1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1

input()
A = list(map(int, input().split()))
index = partition(A, 0, A[len(A) - 1])
for i in range(len(A)):
    if i == index:
        A[i] = '[{}]'.format(A[i])
    else:
        A[i] = str(A[i])
print(' '.join(A))