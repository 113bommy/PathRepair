n=int(input())
p=[int(input()) for _ in range(n)]
ma=max(p)
print(int(sum(p)-ma/2))