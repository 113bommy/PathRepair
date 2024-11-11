N, X = map(int, input().split())
l = [int(input()) for _ in range(N)]

print(3 + (1000 - sum(l)) // min(l))