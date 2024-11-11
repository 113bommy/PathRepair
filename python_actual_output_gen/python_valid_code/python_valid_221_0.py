n, x = map(int, input().split())
l = list(map(int, input().split()))
print(sum(i <= x for i in [sum(l[0:i]) for i in range(n)]))