from sys import stdin, stdout

n,m = map(int, stdin.readline().split())
t = [[0 for i in range(m)] for j in range(n)]

for i in range(n):
    s = stdin.readline().strip()
    for j,c in enumerate(s):
        t[i][j] = c

begins = [[False for i in range(m)] for j in range(n)]
lens = [[0 for i in range(m)] for j in range(n)]

for j in range(m):
    cur_len = 1
    run_start = 0
    for i in range(1,n):
        if t[i-1][j] != t[i][j]:
            begins[run_start][j] = True
            for z in range(run_start, i):
                lens[z][j] = cur_len - (z-run_start)
            cur_len = 0
            run_start = i
        cur_len += 1
    begins[run_start][j] = True
    for z in range(run_start, n):
        lens[z][j] = cur_len - (z-run_start)

#print(begins)
#print(lens)
done = [[False for i in range(m)] for j in range(n)]
ans = 0
for j in range(m):
    for i in range(n):
        if done[i][j]:
            continue
        l = lens[i][j]
        if i+2*l >= n:
            continue
        if not begins[i+l][j] or lens[i+l][j] != l or not begins[i+2*l][j] or lens[i+2*l][j] < l:
            continue
        num_cols = 1
        cur_j = j
        while cur_j < m and lens[i][cur_j] == l and begins[i+l][cur_j] and lens[i+l][j] == l and begins[i+2*l][cur_j]and lens[i+2*l][cur_j] >= l and t[i][cur_j] == t[i][j] and t[i+l][cur_j] == t[i+l][j] and t[i+2*l][cur_j] == t[i+2*l][j]:
            done[i][cur_j] = True 
            cur_j += 1
        num_cols = cur_j - j

        ans += num_cols*(num_cols+1) // 2

print(ans)        

