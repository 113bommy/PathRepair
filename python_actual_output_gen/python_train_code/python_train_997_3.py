n, k = [int(x) for x in input().split(' ')]
A = input().split(' ')

to_compare = A[k-1]
possible = True
for i in range(k-1, n):
    if A[i] != to_compare:
        possible = False
        break

if not possible:
    print(-1)
else:
    result = -1
    for i in range(k-2, -1, -1):
        if A[i] != to_compare:
            result = i + 1
            break
    print(result)