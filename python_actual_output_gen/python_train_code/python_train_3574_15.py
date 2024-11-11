n, k = map(int, input().split())
d = tuple(map(str, input().split()))
for i in range(n, 10001):
    b = True
    for s in tuple(str(i)):
        if s in d:
            b = False
            break
    if b:
        print(i)
        exit()
