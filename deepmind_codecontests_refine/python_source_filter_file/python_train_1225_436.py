n,k = map(int, input().split())
p = list(map(int, input().split()))

print(sum(sorted(p)[:n+1]))
