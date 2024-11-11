n = int(input())
a = list(map(int, input().split()))

b = [0] * n
for i in range(n):
    b[i] = set()

c = 1
for elem in a:
    for i in range(c):
        if not (elem in b[i]):
            b[i].add(elem)
            break
    else:
        b[c].add(elem)
        c += 1
print(c)