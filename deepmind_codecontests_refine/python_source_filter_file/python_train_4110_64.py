score = (lambda p, t: max(75, 250 - t))
a, b, c, d = map(int, input().split())
print('Misha' if score(a, c) > score(b, d) else 'Vasya' if score(a, c) < score(b, d) else 'Tie')