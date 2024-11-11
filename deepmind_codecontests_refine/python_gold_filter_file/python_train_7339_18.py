a = [8 for _ in range(8)]
b = [8 for _ in range(8)]
for r in range(8):
    row = input()
    for i, c in enumerate(row):
        if c == "W":
            if a[i] == b[i] == 8:
                a[i] = r
            b[i] = 9
        elif c == "B":
            b[i] = 7 - r
# print(a)
# print(b)
a = min(a)
b = min(b)
print("A" if a <= b else "B")
