import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

s = input()
N = len(s)
if s[0] == '0' or s[-1] == '1' or s[:-1] != s[:-1][::-1]:
    print(-1)
    exit()
subtree = [[] for _ in range(N+1)]
prev = 1
for i in range(2, N+1):
    if s[i-1] == '1' or i == N:
        subtree[i] = [prev] + [1] * (i-prev-1)
        prev = i

i = 1
def dfs(size):
    global i
    v = i
    for c in subtree[size]:
        i += 1
        print(v, i)
        dfs(c)

dfs(N)