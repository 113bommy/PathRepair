n, v = map(int, input().split())
sel = []
for _ in range(n):
    n, *item = map(int, input().split())
    for i in item:
        if i < v:
            sel.append(n)
            break
print(len(sel))
print(*sorted(sel), sep=" ")
