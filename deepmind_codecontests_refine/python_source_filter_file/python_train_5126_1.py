t = int(input())

for _ in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))

    visited = set()
    for i in range(n):
        visited.add(a[i])

    for i in range(1, 201):
        if i not in visited:
            x -= 1

            if x == -1:
                print(i - 1)
                break
