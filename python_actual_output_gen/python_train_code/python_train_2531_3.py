a = b = []
last = 0
for i in range(int(input())):
    j = int(input())
    if j > 0:
        last = 1
        a.append(j)
    else:
        last = 0
        b.append(-j)
suma = sum(a)
sumb = sum(b)
if suma > sumb or (suma == sumb and a > b) or (suma == sumb and a == b and last == 1):
    print("first")
else:
    print("second")