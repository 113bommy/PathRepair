def binary_search(x, arr, left, right):
    if right - left == 1:
        return left
    med = (right + left) // 2
    if arr[med] <= x:
        return binary_search(x, arr, med, right)
    return binary_search(x, arr, left, med)


t = int(input())
for i in range(t):
    n, m, a, b = tuple(map(int, input().split(' ')))
    firecrackers = sorted(list(map(int, input().split(' '))))

    remaining_time = b - 2 if a < b else n - b - 1
    before_caught = abs(a - b)
    most_possible_index = binary_search(remaining_time, firecrackers, 0, m)

    ideal_drops = 0
    while most_possible_index >= 0:
        if firecrackers[most_possible_index] <= remaining_time:
            ideal_drops += 1
            most_possible_index -= 1
            remaining_time -= 1
        while firecrackers[most_possible_index] > remaining_time:
            most_possible_index -= 1
            if most_possible_index < 0:
                break

    print(min(before_caught, ideal_drops))
