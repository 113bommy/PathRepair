w1, h1, w2, h2 = map(int, input().split())

print(w2 + h2 * 2 + 2 + w1 + 2 * h2 + 2 + abs(w1-w2))
