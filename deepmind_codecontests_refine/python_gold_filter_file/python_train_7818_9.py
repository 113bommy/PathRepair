from collections import defaultdict
n, m = map(int, input().split())
pairs = defaultdict(set)
for _ in range(m):
    l, r = map(int, input().split())
    pairs[l-1].add(r-1)
    pairs[r-1].add(l-1)
answers = defaultdict(list)
free_rooks = defaultdict(int)
y = 1
for color in range(n):
    free_rooks[color] = y
    for c in pairs[color]:
        if c < color:
            answers[color].append((color + 1, free_rooks[c]))
            free_rooks[c] += 1
        else:
            answers[color].append((color + 1, y))
            y += 1
    answers[color].append((color + 1, y))
    y += 1
for color in range(n):
    print(len(answers[color]))
    for x, y in answers[color]:
        print(x, y)
