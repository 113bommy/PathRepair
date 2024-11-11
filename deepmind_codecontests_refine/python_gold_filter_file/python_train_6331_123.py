N = int(input())
N = [int(input()) for i in range(N)]

print(sum(N) - max(N) // 2)