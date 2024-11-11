def inp():
    return map(int, input().split())
def li():
    return list(inp())
k, n, s, p = inp()
print((k * (n + s - 1) // s + p - 1) // p)
