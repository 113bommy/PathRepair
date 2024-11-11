N = int(input())
p = [int(input()) for _ in range(N)]
print(sum(p) - int(max(p)//2))