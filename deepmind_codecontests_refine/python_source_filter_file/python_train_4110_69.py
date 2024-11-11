ss = lambda: input()
si = lambda: int(input())

a, b, c, d = map(int, input().split())
score = lambda p, t: max(3 * p / 10, p - p / 250 * t)

misha, vasya = score(a, c), score(b, d)

if (misha > vasya):
    print("Misha")
elif (misha < vasya):
    print("Vashya")
else:
    print("Tie")
