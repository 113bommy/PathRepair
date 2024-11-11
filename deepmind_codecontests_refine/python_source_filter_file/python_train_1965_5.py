import sys
x = 500000
f = [0, 1] * xx
i = 3

while i * i <= 2 * xx:
    if f[i] == 1:
        j = i * i
        while j <= 2 * xx:
            f[j] = 0
            j += i + i
    i += 2

f.pop(0)
f.pop(1)

for n in sys.stdin:
    i = int(n)
    if i < 2:
        print(0)
    else:
        print(sum(f[:i - 1]))