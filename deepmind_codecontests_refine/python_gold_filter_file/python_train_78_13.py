n = int(input())

def dfs(s, mx):
    if len(s) == n:
        print(s)
    else:
        for i in range(0, mx +1):
            c = chr(ord('a')+i)
            dfs(s+c, mx +1) if i == mx else dfs(s+c, mx)

dfs('', 0)