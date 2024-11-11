N = int(input())
g = list(map(int, input().split()))
g.sort()
print(sum(g[N::2]))