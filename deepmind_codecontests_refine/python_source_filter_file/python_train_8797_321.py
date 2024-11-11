x = int(input())
d = x / 5
r = x % 5
if 1 <= x <= 5:
    print('1')
elif r == 0:
    print(d)
elif 1 <= r <= 5:
    d += 1
    print(int(d))
