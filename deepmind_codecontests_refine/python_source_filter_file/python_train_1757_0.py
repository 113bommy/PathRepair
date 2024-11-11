import math
n = 7
x = [1 for i in range(n)]
y = [0 for i in range(n)]
ang = 0
for i in range(2, n):
    ang += math.asin(1/math.sqrt(i - 1))
    x[i] = x[i - 1] + math.cos(ang)
    y[i] = y[i - 1] + math.sin(ang)

while True:
    n = int(input())
    if n == -1:
        break
    print(x[n])
    print(y[n])

