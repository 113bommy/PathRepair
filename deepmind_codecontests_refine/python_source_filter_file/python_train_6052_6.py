s = input()

i = 1
j = 0
for c in s:
    if c == "0":
        i += 1
        print(1, 1 + (i % 2) * 2)
    else:
        print(3, 1 + j % 4)
        j += 1
