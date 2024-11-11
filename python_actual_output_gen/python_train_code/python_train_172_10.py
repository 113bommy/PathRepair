m = list(map(int, input().split()))
w = list(map(int, input().split()))
h = list(map(int, input().split()))
x = sum([max(0.3 * x * 500, ((1 - (t / 250)) * x * 500) - (50 * a)) for x, t, a in zip(range(1, 6), m, w)]) + (
            h[0] * 100) + (h[1] * 50)
print(int(x))
