#!/usr/bin/python3

input()
string = input()

colors = [0] * 26
res = []
visited = set()

for char in string:
    i1 = ord(char) - ord('a')
    color = 0
    for v in visited:
        i2 = ord(v) - ord('a')
        if char < v:
            color = max(colors[i1], colors[i2])
    color += 1
    colors[i1] = color
    res.append(color)
    visited.add(char)

print(max(colors))
print(' '.join(str(i) for i in res))