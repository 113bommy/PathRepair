def new_route(lst):
    big, count = 10 ** 18, 0
    for i in range(1, len(lst)):
        f = lst[i] - lst[i - 1]
        if f == big:
            count += 1
        if f < big:
            big, count = f, 1
    return big, count


n = int(input())
a = [int(j) for j in input().split()]
print(new_route(sorted(a)))
