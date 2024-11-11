import itertools

p, x, y = map(int, input().split())
d = (x - y) // 50
p -= 26
i0 = x // 50 % 475
for k in itertools.count(-d):
    i = (i0 + k) % 475
    for _ in range(25):
        i = (i * 96 + 42) % 475
        if i == p:
            print(0 if k < 2 else (k + 1) // 2)
            exit()
