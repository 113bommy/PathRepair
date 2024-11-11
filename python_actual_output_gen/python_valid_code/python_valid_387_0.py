def insertion_sort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j -= g
            cnt += 1
        A[j + g] = v


def shell_sort(A, n):
    G = []
    i = 1
    while i < n:
        G[0:0] = [i]
        i = i * 3 + 1
    for g in G:
        insertion_sort(A, n, g)
    return len(G), G

N = int(input())
a = [int(input()) for i in range(N)]
cnt = 0
m, Gl = shell_sort(a, N)
print(m, ' '.join(str(g) for g in Gl), '\n'.join(str(e) for e in a), sep='\n')