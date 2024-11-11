n = int(input())
s = ""


if n > 1:
    for i in range(1, n + 1):
        if i % 2 != 0:
            s += "I hate"
        else:
            s += "I love"
        if i == n:
            s += " it"
        else:
            s += " that "
else:
    s = "I hate it"
        