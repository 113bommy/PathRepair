h, i = map(int, input().split())
k, l = map(int, input().split())
a, b, c, d = map(int, input().split())
p = h * a + h // 10 * c + i * b + i // 10 * d
q = k * a + k // 10 * c + l * b + l // 10 * d
if p == q:print("even")
else:print("hiroshi" if p > q else "kenjiro")
