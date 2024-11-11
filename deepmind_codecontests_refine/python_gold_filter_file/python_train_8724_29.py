(n, m) = map(int, input().split())
l = [set(list(map(int, input().split()))[1:]) for _ in range(n)]
print(len(l[0].intersection(*l[1:])))