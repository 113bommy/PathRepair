k, n, w = map(int, input().split())
w1 = k
for i in range(2, w + 1) :
    w1 += k * i
if w1 - n == 0:
    print(0)
else:
    print(w1 - n)