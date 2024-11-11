x, n = map(int, input().split())
P = list(map(int, input().split()))

koho = [i for i in range(1, 101) if i not in P]

koho.sort(key=lambda a: (abs(a - x), a))

print(koho[0])