n = int(input())

def dfs(s, mx):
    if len(s) == n:
        print(s)
    else:
        for c in [chr(ord('a') + i) for i in range(ord(mx) - ord('a') + 1)]:
            dfs(s + c, chr(ord(mx) + 1) if c == mx else mx)

dfs('', 'a')