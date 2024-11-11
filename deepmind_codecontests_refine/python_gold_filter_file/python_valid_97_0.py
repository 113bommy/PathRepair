from collections import defaultdict
import sys
m, n = [int(i) for i in input().split()]
d = ['' for i in range(m)]
for i in range(m):
    d[i] = input()
op = defaultdict(list)
r = [[-1] * n for i in range(m)]
for i in range(m):
    for j in range(n):
        if d[i][j] == 'X':
            t = []
            for a,b in [(i,j-1),(i-1,j),(i,j+1),(i+1,j)]:
                if 0<=a<m and 0<=b<n and d[a][b] == '.':
                    t.append((a,b))
            if len(t) % 2:
                print('NO')
                sys.exit()
            if len(t) == 0: r[i][j] = 0
            if len(t) == 2:
                op[t[0]].append(t[1])
                op[t[1]].append(t[0])
                r[i][j] = 5
            if len(t) == 4:
                op[t[0]].append(t[1])
                op[t[1]].append(t[0])
                op[t[2]].append(t[3])
                op[t[3]].append(t[2])
                r[i][j] = 10

for a in range(m):
    for b in range(n):
        if r[a][b] == -1:
            r[a][b] = 1
            st = [(a,b)]
            while st:
                i,j = st.pop()
                for x,y in op[(i,j)]:
                    if r[x][y] == -1:
                        r[x][y] = 5 - r[i][j]
                        st.append((x,y))
                    else:
                        if r[x][y] != 5 - r[i][j]:
                            print('NO')
                            sys.exit()


print('YES')
for i in range(m):
    print (' '.join('1' if r[i][j] == -1 else str(r[i][j]) for j in range(n)))
