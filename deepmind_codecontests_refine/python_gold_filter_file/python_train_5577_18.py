n, a, b, c = map(int, input().split())
mod = n % 4
if mod == 0:
    print(0)
elif mod == 1:
    print(min(3 * a, a + b,  c))
elif mod == 2:
    print(min(2 * a, b, 2 * c))
elif mod == 3:
    print(min(a, b + c, 3 * c))
