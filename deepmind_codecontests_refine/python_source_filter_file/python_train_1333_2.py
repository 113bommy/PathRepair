X = [int(input(_)) for _ in range(5)]

S = [round(x + 4.9, -1) for x in X]
d = [round(x + 4.9, -1) - x for x in X]

print(int(sum(S) - max(d)))
