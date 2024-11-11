n = int(input())
a = input() + ' '
count = 0
counts = a.count("(")
for x in range(counts):
    try:
        start = a.index("(")
        stop = a.index(")")
        b = a[start:stop + 1].strip("()").split("_")
        for x in b:
            if len(x) > 0:
                count += 1
        a = a[:start]+"_" + a[stop + 1:]
    except:
        pass
a = a.strip("_ ").split("_")
print(a)
c = [len(x) for x in a]
print(max(c), count)
