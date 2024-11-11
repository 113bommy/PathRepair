H, W, A, B = map(int, input().split())

lst = [[0 if (i < A and j < B) or (A <= i and B <= j) else 1 for j in range(H)] for i in range(W)]

for i in lst:
    print (*i, sep = '')