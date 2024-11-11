n, prev = int(input()), ""
a = [input().split() for _ in range(n)]
p = [int(i) - 1 for i in input().split()]
for i, v in enumerate(p):
    if i == 0:
        prev = min(a[v][0], a[v][1])
    else:
        if min(a[v][0], a[v][1]) > prev:
            prev = min(a[v][0], a[v][1])
        elif max(a[v][0], a[v][1]) > prev:
            prev = max(a[v][0], a[v][1])
        else:
            print("No")
            exit()
print("YES")