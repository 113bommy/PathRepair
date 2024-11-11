from queue import Queue

n = int(input())
A = [[0 for i in range(n)] for j in range(n)]
d = [-1 for i in range(n)]

for i in range(n):
    u, k, *v = list(map(int, input().split()))
    for j in v:
        A[int(u)-1][int(j)-1] = 1

q = Queue()
q.put(0)
d[0] = 0

while not q.empty():
    u = q.get()
    # print('visited:', u)
    for v in range(n):
        # print(u, v)
        if A[u][v] == 1 and d[v] == -1:
            q.put(v)
            d[v] = d[u] + 1

# print('-========')
for i in range(n):
    print(i, d[i])
