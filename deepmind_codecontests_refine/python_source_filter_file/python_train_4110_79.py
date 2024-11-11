a, b, c, d = map(int, input().split())

first = max((3 * a) / 10, a - ((a / 250) * c))
second = max((3 * b) / 10, b - ((b / 250) * d))

if first == second:
    print("tie")
elif first > second:
    print("Misha")
else:
    print("Vasya")