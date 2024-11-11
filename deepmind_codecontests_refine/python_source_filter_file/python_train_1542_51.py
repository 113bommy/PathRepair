N, *A = map(int, open(0).read().split())

A = [0] + A
B = [0] * (N + 1)
sum_B = 0
for i in range(N, 0, -1):
    if sum(B[j] for j in range(i, N + 1, i)) != A[i]:
        B[i] = 1
        sum_B += 1
print(sum_B)
print(*[i for i, b in enumerate(B) if b])
