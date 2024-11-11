x = abs(int(input()))
k, s, i = 0, 0, 1
while s < x or (s - x) % 2 == 1:
    s += i
    i += 1
print(i - 1)
