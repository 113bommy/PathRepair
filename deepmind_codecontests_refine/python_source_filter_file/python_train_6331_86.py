N = int(input())
p = [int(input()) for _ in N]
print(sum(p) - max(p) // 2)
