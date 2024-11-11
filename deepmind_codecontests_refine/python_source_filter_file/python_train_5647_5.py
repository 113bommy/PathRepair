n_sets = int(input())
for _ in range(n_sets):
    n, m = map(int, input().split())
    print("W", "B" * (m-1))
    for i in range(1, n):
        print("B"*m)
