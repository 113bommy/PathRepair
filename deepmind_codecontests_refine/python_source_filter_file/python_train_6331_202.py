n = int(input(0))
p = [int(input()) for _ in range(n)]
print(sum(p) - max(p)//2)
