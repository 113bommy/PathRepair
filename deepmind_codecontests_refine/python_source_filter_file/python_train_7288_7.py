def counting_sort(A, k):
    C = [0 for i in range(k)]
# C[i]にiの出現数を記録する
    for l in A:
        C[l] += 1
# C[i]にi以下の数の出現数を記録する
    for i in range(1, k):
        C[i] = C[i] + C[i-1]

    B = [None for i in range(len(A))]
    for l in A[::-1]:
        B[C[l]-1] = l
        C[l] -= 1

    return B

input()
a = list(map(int, input().split()))
b = counting_sort(a, 10)
print(*b)
