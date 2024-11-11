w1 = []
w2 = []
last = 1
for _ in range(int(input())):
    x = int(input())
    if x > 0:
        w1.append(x)
        last = 1
    else:
        w2.append(-x)
        last = 2
sw1 = sum(w1)
sw2 = sum(w2)
if sw1 > sw2 or (sw1 == sw2 and w1 > w2) or (sw1 == sw2 and w1 == w2 and last == 1):
    print("first")
else:
    print("second")
