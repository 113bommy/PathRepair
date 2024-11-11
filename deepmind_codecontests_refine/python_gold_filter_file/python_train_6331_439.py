n = int(input())
P = [int(input()) for _ in range(n)]

print(sum(P) - max(P) // 2)
