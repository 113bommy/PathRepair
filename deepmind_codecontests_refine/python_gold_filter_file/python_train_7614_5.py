n, m, h = map(int, input().split())

sol = [[h for _ in range(m)] for _ in range(n)]

#print(sol)

frente = list(map(int, input().split()))
lado = list(map(int, input().split()))

for i in range(n):
    for j in range(m):
        sol[i][j] = min(sol[i][j], frente[j])

for j in range(m):
    for i in range(n):
        sol[i][j] = min(sol[i][j], lado[i])


for i in range(n):
    top = list(map(int, input().split()))
    for j in range(m):
        if top[j] == 0:
            sol[i][j] = 0

for l in sol:
    print(" ".join(str(x) for x in l))

