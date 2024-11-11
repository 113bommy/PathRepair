N = int(input())
p = [int(input()) for _ in range(N)]
print(int(sum(p) - max(p)/2))
