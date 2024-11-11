N = int(input())
A = [int(input()) for _ in range(N)]
print(sum(A) - max(A) // 2)