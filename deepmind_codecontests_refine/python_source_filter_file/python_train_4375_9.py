def mergesort(A, s, e):
    if s + 1 < e:
        m = (e + s) // 2
        mergesort(A, s, m)
        mergesort(A, m, e)
        merge(A, s, m, e)


def merge(A, s, m, e):
    L = A[s:m] + [('*', 1E10)]
    R = A[m:e] + [('*', 1E10)]
    ix_l = ix_r = 0
    for ix in range(s, e):
        if L[ix_l][1] < R[ix_r][1]:
            A[ix] = L[ix_l]
            ix_l += 1
        else:
            A[ix] = R[ix_r]
            ix_r += 1


def partition(A, p, r):
    x = A[r][1]
    i = p - 1
    for j in range(p, r):
        if A[j][1] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1


def quicksort(A, p, r):
    if p < r:
        i = partition(A, p, r)
        quicksort(A, p, i - 1)
        quicksort(A, i + 1, r)



if __name__ == '__main__':
    N = int(input().strip())
    AA = [0] * N
    for i in range(N):
        key, val = input().strip().split()
        val = int(val)
        AA[i] = (key, val)
    AA2 = AA[:]
    quicksort(AA, 0, len(AA) - 1)
    mergesort(AA2, 0, len(AA2))
    if all([a == a2 for a, a2 in zip(AA, AA2)]):
        print('Stable')
    else:
        print('Not stable')
    for key, val in AA:
        print('{} {}'.format(key, val))