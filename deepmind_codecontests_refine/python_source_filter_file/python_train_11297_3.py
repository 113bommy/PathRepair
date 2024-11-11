def handle(x):
    return (x.translate({ord(c): None for c in "-_:"})).lower()

a = handle(input())
b = handle(input())
c = handle(input())
s = set()
s.add(a + b +c)
s.add(a + c +b)
s.add(b + a +c)
s.add(b + c +a)
s.add(c + b +a)
s.add(c + a +b)
n = int(input())
for _ in range(n):
    x = input()
    x = handle(x)
    if x in s:
        print("ACC")
    else:
        print("WA")

