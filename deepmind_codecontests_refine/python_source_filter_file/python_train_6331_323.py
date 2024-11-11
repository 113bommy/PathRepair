n = int(input())
p = [int(input()) for _ in range(n)]
print(p.sum() - p.max()//2)