import sys
readline = sys.stdin.readline
def insertionSort(A, n, g, cnt):
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
    h = 1
    G = []
    while h < n:
        G += [h]
        h = 3 * h + 1
    m = len(G)
    for i in range(m - 1, -1, -1):
        cnt = insertionSort(A, n, G[i], cnt)
    print(m)
    print(*G[::-1])
    print(cnt)
    print(*A, sep="\n")
n = int(input())
A = [int(readline()) for _ in range(n)]
shellSort(A, n)

