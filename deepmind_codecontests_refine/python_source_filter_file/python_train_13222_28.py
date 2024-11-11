import sys

def isort(A, n, g):
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

def ssort(A, n):
    cnt = 0
    G = []
    h = 1
    while h < n:
        G.append(h)
        h = 3 * h + 1
    m = len(G)
    G = reversed(G)
    print(m)
    print(*G, sep = " ")
    for g in G:
        cnt += isort(A, n, g)
    return cnt

n = int(input())
A = list(map(int, sys.stdin.readlines()))
cnt = ssort(A, n)
print(cnt)
print(*A, sep = "\n")