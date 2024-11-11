n = int(input())
p = [int(input()) for _ in range(n)]
m = max(p)
print(sum(p)-m//2)
