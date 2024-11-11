n = int(input())
p = [int(input()) for _ in range(5)]
print((n - 1) // min(p) + 5)