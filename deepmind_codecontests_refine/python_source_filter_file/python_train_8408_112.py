x = int(input())
d = {}
for a in range(-200, 200):
    for b in range(-200, 200):
        k = a**5 - b**5
        d[k] = [a, b]
print(*d[k])