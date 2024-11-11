x = int(input())
p = 0
i = 1
while p != x:
    if x - p >= i:
        p += i
    elif x - p <= - i:
        p -= i
    elif abs(p - x) > i / 2:
        if x > p:
            p += i
        else:
            p -= i
    else:
        break
    i += 1
a = i + 10
if x < p < 0 or x > p > 0:
    a = i + 2 * abs(p - x) - 1
    if p < 0:
        p -= i
    if p > 0:
        p += i
    i += 1
if abs(p - x) % 2 != 0:
    if i % 2 != 0:
        i += 1
    else:
        i += 2
i -= 1
print(min(i, a))