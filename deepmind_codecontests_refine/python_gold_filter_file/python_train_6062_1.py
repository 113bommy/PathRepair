t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    total = sum(a)
    if m <= total:
        print(m)
    else:
        print(total)
