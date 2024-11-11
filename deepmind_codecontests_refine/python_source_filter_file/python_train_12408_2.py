l, r = list(map(int, input().split(' ')))
x = l
digits = set(str(x))
while len(digits) != len(str(x)) and x <= r:
    x += 1
    digits = set(str(x))
if x < r:
    print(x)
else:
    print(-1)