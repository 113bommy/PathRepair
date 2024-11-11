n_sets = int(input())
for _ in range(n_sets):
    r, g, b = sorted(list(map(int, input().split())))
    if b <= r + g:
        print("Yes")
    else:
        print("No")