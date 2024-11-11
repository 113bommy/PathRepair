
#import time
#startTime = time.time()

n, m = [int(i) for i in input().split()]

graf = [[] for i in range(n)]
for i in range(m):
    a, b = [int(i)-1 for i in input().split()]
    graf[a].append(b)
    graf[b].append(a)

#print(graf)

def equals(v, w):
    a = graf[v].copy()
    #print(a, end=' ')
    a.remove(w)
    b = graf[w].copy()
    #print(b)
    b.remove(v)
    if sorted(a).__eq__(sorted(b)):
        return True
    return False

visited = [False] * n

def dfs(v):
    visited[v] = True
    for w in graf[v]:
        if visited[w] == False:
            if equals(v, w):
                if not dfs(w):
                    return False
            else:
                #print('v ', v, 'w ', w)
                return False
    return True

boo = False
for i in range(n):
    if visited[i] == False:
        if not dfs(i):
           #print('Not')
           boo = True
           break
print('YES' if not boo else 'NO')
#print('----------%s sec----------' % (time.time() - startTime))