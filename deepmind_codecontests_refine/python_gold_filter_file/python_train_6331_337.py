N = int(input())
P = [int(input()) for j in range(N)]
print(sum(P) - max(P) // 2)