N = int(input())

def printCompleteGraph(n):
    edge = [(u, v) for u in range(n)
                   for v in range(u + 1, n)
                   if u != v]
    name = {e: i+1 for i, e in enumerate(edge)}
    for u in range(n):
        e = [name[(min(u, v), max(u, v))] for v in range(n) if u != v]
        print(len(e), ' '.join(map(str, e)))

for n in range(2, max(N, 2) + 1):
    if n * (n - 1) // 2 == N:
        print('Yes')
        print(n)
        printCompleteGraph(n)
        exit()
print('No')
