from sys import stdin
from typing import DefaultDict; read = stdin.readline
 
def fun1(node, tot):
    for i in range(1, tot+1):
        if i != node: print(i, node)

for _ in range(int(read())):
    n, m = map(int, read().split())

    res = [0 for i in range(n+1)]
    dic = DefaultDict(lambda : [])
    for i in range(m):
        a, b, c = map(int, read().split())
        res[b] += 1
        dic[b].append((a,c))

    print(res)
    for i in range(1, n+1):
        if res[i] == 0: fun1(i, n); break
    else:
        print(*dic[1])
        for i in range(1, n+1):
            if i != 1 and i != dic[1][0][0] and i != dic[1][0][1]: print(i, 1)