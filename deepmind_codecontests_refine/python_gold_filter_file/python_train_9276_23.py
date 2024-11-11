n = int(input())
a = [i for i in range(1, 101)]
for i in range(n):
    b = [int(i) for i in input().split()][1:]
    c = []
    for el in a:
        if el in b:
            c.append(el)
    a = c[:]
print(*a)