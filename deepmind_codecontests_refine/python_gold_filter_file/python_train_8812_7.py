n, k, M, D = list(map(int, input().split(" ")))

gain = 0

for i in range(1, D + 1):
    x = n // ((i - 1) * k + 1)
    
    x = min(M, x)

    if x > 0:
        true_d = (n // x + k - 1) // k
        if true_d != i:
            continue

        gain = max(gain, x * i)

print(gain)
