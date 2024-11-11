def solve(v):
    v.sort()
    for a, b, c in zip(v[:-2], v[1:-1], v[2:]):
        if c < a+b:
            return True
    return False

print(["NO", "YES"][solve(
    list(map(int, input().split()))
)])