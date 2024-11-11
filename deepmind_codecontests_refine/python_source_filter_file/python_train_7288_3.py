def counting_sort(A, k):
    B = [0] * len(A)
    C = [0] * k

    for a in A:
        C[a] += 1

    for i in range(1, k):
        C[i] += C[i - 1]

    for a in reversed(A):
        B[C[a] - 1] = a
        C[a] -= 1

    return B


def main():
    n = int(input())
    A = [int(x) for x in input().split()]
    print(*counting_sort(A, 11))


main()
