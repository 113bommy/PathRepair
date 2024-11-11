s = k = j = 0
for i in input():
    if i == j: k += 1
    else:
        s += k % 2
        k, j = 0, i
print(s)