n = int(input())
p = list(int(input()) for _ in range(n))

print(sum(p) - max(p)//2)