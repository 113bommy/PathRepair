import math

def insertionSort(A, n, g):
    cnt = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j -= g
            cnt += 1
        A[j + g] = v
    return cnt


def shellSort(A, n):
    cnt = 0
    j = int(math.log(2 * max(A) + 1, 3)) + 1
    G = list(reversed([(3 ** i - 1)// 2 for i in range(1, j)]))
    m = len(G)
    for i in range(m):
        cnt += insertionSort(A, n, G[i])
    return A, cnt, G, m

n = int(input())
A = [int(input()) for i in range(n)]
ans, count, G, m = shellSort(A, n)
print(m)
print(' '.join(map(str,G)))
print(count)
[print(i) for i in A]