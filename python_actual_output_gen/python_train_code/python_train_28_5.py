n = int(input())

def dfs(s,mx):
    if len(s)==n:
        print(s)
        return None
    for i in range(ord('a'),(mx+1)+1):
        dfs(s+chr(i),max(mx,i))
dfs('',ord('a'))