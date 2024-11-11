# 0028
array = []
while True:
    try:
        a = input()
        array.append(int(a))
    except EOFError:
        break
s = set(array)
count= list(map(lambda a: array.count(a), s))
mx = max(count)
modes = list(list(s)[i] for i, x in enumerate(count) if x == mx)
print(*sorted(modes), sep = '\n')