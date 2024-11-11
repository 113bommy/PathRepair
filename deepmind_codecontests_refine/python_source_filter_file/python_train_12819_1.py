from sys import stdin, stdout

def find(node):
    x = []
    while dsu[node] > 0:
        x.append(node)
        node = dsu[node]
    for i in x:
        dsu[i] = node
    return node

def union(node1, node2):
    if node1 != node2:
        if dsu[node1] > dsu[node2]:
            node1, node2 = node2, node1
        dsu[node1] += dsu[node2]
        dsu[node2] = node1

n = int(stdin.readline().strip())
dsu = [-1 for i in range(n**2 + 1)]
a, b = map(int, stdin.readline().strip().split())
c, d = map(int, stdin.readline().strip().split())
s = ' '
for i in range(n):
    cur = stdin.readline().strip()
    s += cur
    for j in range(n):
        if cur[j] == '0':
            if j != 0:
                if cur[j-1] == '0':
                    union(find(i*n + j), find(i*n + (j+1)))
            if i != 0:
                if s[(i-1)*n + j+1] == '0':
                    union(find(i*n+j+1), find((i-1)*n+j+1))
p_a = find((a-1)*n + b)
p_b = find((c-1)*n + d)
if p_a == p_b:
    stdout.write('0')
else:
    arr_a = []
    arr_b = []
    for i in range(1,n**2 + 1):
        c_p = find(i)
        if c_p == p_a:
            arr_a.append(i)
        elif c_p == p_b:
            arr_b.append(i)
        else:
            continue
    minm = 200
    for i in arr_a:
        x1 = i//n if i%n == 0 else (i//n)+1
        y1 = i - (x1-1)*n
        for j in arr_b:
            x2 = j//n if j%n == 0 else (j//n)+1
            y2 = j - (x2 - 1) * n
            val = abs(x2-x1)**2 + abs(y2-y1)**2
            minm = min(minm, val)
    stdout.write(f'{minm}')

