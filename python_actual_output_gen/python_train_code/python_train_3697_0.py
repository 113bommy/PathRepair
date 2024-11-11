n, m = map(int, input().split(' '))
G = [[0]*n for i in range(n)]

for i in range(m):
    u, v = map(lambda x:int(x)-1, input().split(' '))
    G[u][v] = G[v][u] = 1

s = [' ']*n

for i in range(n):
    if G[i].count(1) == n-1:
        s[i] = 'b'

try:
    anode = s.index(' ')
    s[anode] = 'a'
except:
    print('Yes')
    print(''.join(s))
    exit()

for i in range(n):
    if s[i] == ' ' and G[anode][i] == 1:
        s[i] == 'a'
    elif s[i] == ' ' and G[anode][i] == 0:
        s[i] == 'c'

for i in range(n):
    for j in range(i+1, n):
        if (s[i] != s[j] and s[i] != 'b' and s[j] != 'b') == G[i][j]:
                print('No')
                exit()

print('Yes')
print(''.join(s))
