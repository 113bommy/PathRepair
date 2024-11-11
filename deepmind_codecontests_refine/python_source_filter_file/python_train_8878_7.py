def mask(x):
    return True if ''.join(list(filter(lambda x: x in ['4', '7'], str(x)))) == b else False


a, b = map(int, input().split())
b = str(b)

for i in range(a + 1, 100001):
    if mask(i):
        exit(print(i))
