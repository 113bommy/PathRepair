# 0028
array = []
while True:
    try:
        a = input()
        array.append(int(a))
    except EOFError:
        break
s = set(array)
mx = max(list(map(lambda a: array.count(a), s)))
modes = list(filter(lambda a: array.count(a) == mx, sorted(s)))
print(*modes, sep = '\n')