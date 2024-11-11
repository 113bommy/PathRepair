N, *A = [int(_) for _ in open(0).read().split()]
sumB = max(0, sum(A) - N * (N - 1))
while True:
    B = [0 - (-(a + x + 1 - N)) // (N + 1) for a in A]
    if sumB == sum(B):
        break
    sumB += 1
print(sumB)
