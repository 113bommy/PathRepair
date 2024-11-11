def counting_sort(A, B, k):
    len_A = len(A)

    C = [0 for _ in range(k + 1)]

    for j in range(len_A):
        C[A[j]] += 1

    for i in range(1, k + 1):
        C[i] = C[i] + C[i - 1]

    for j in range(len_A - 1, -1, -1):
        B[C[A[j]] - 1] = A[j]
        C[A[j]] -= 1


n = int(input())
input_list = list(map(int, input().split(' ')))

B = [0 for _ in range(n)]

counting_sort(input_list, B, max(input_list) + 1)

print(B)
