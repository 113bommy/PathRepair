a, b, c, d = map(int, input().split())
n = 1000
s = a/b
prev_term = a/b
for i in range(n):
    prev_term *= (a/b) * ((d-c)/d)
    s += prev_term
print(s)