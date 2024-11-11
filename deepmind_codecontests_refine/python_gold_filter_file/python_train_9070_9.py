w1, h1, w2, h2 = map(int, input().split())
print((w1 + (2 * h1)) + (w2 + (2 * h2)) + abs(w1 - w2) + 4)