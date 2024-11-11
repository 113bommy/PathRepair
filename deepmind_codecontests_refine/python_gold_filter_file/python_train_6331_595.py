N = int(input())
P = [int(input()) for n in range(N)]

print(sum(P) - max(P) // 2)