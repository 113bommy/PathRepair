n, m, k = map(int, input().split())
lista = sorted(map(lambda x: (x[1], x[0]), enumerate(map(int, input().split()))))[-m*k:]
[l1, l2] = zip(*lista)
print(sum(l1))
print(*(list(map(lambda x: x + 1, (sorted(l2))[m - 1:: m]))[:k-1]))