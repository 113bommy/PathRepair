import sys
input = sys.stdin.readline


def qsort(A, left, right):
    while left < right:
        q = partition(A, left, right)
        if (q - 1) - left < right - (q + 1):
            qsort(A, left, q-1)
            left = q + 1
        else:
            qsort(A, q+1, right)
            right = q - 1


def partition(A, left, right):
    q = A[right]
    i = left - 1
    for j in range(left, right):
        if abs(A[j]) < abs(q):
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[right] = A[right], A[i+1]
    return i+1


def solve(miners, mines, n):
    qsort(miners, 0, n - 1)
    qsort(mines, 0, n - 1)
    # miners.sort()
    # mines.sort()
    total = 0
    for i in range(n):
        total += distance(miners[i], mines[i])

    print(total)


def distance(miner, mine):
    return (miner * miner + mine * mine) ** (1/2)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        mines = []
        miners = []
        for _ in range(2*n):
            coords = [int(x) for x in input().split()]
            if coords[0]:
                mines.append(abs(coords[1]))
            else:
                miners.append(abs(coords[0]))

        solve(miners, mines, n)