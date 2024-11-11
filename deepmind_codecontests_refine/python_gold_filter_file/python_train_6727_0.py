symbol = ["a", "e", "i", "o", "u"]
a = input()
i = 2
while i < len(a):
    if not (a[i] in symbol) and not(a[i - 1] in symbol) and not (a[i - 2] in symbol) and a[i - 2:i + 1] != a[i - 2] * 3:
        a = a[:i] + " " + a[i:]
        i = i + 3
    else:
        i = i + 1
print(a)
