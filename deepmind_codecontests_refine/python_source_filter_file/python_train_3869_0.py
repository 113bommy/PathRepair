n = int(input())
arr = [int(x) for x in input().split()]

counts = [0] * 100000
count_to_color = {}

mx = 0
for i in range(n):
    color = arr[i] - 1
    print(i, color, count_to_color)

    if counts[color] > 0:
        count_to_color[counts[color]].remove(color)
        if not count_to_color[counts[color]]:
            del count_to_color[counts[color]]
    counts[color] += 1
    count = counts[color]

    if count not in count_to_color:
        count_to_color[count] = set()
    count_to_color[count].add(color)

    if len(count_to_color) == 1:
        if 1 in count_to_color:
            mx = max(mx, i)
        if len(list(count_to_color.values())[0]) == 1:
            mx = max(mx, i)
    if len(count_to_color) == 2:
        count_keys = sorted(list(count_to_color.keys()))
        if count_keys[0] == 1 and len(count_to_color[count_keys[0]]) == 1:
            mx = max(mx, i)
        if count_keys[0] + 1 == count_keys[1] and len(count_to_color[count_keys[1]]) == 1:
            mx = max(mx, i)

print(mx + 1)
