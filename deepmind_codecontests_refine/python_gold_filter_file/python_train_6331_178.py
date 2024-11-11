N = int(input())
p = [int(input()) for n in range(N)]

print(sum(p) - max(p) // 2)