n, k, l, c, d, p, nl, np = map(int, input().split())
w = (k * l) // nl
x = c * d
y = p / np
z = (min(w, x, y)) // n
print(z)
