def iter(a):
    m = max(a)
    return [m-a for a in a]
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    iter(a)
    if not k%2: iter(a)
    print(*a)