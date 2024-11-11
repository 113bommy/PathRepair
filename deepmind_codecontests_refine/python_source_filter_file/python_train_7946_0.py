
n, t1, t2, k = map(int, input().split())

dwarves = []

for i in range(n):
    a, b = map(int, input().split())
    dwarves += [[max([t1 * a * (100 - k) / 100 + t2 * b,
                      t1 * b * (100 - k) / 100 + t2 * a]),
                 i]]

dwarves.sort()
for i in range(n):
    dwarves[i] += [i + 1]

dwarves.sort(key=lambda x: (-x[0], x[1]))

for result, index, _ in dwarves:
    print(index + 1, round(result, 2))
