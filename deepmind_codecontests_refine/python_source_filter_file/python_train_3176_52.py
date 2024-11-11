def solve(n, t):
    if len(str(t)) > n:
        return -1
    n = n if t<10 else n - len(str(t))
    num = int("1" * n)
    num = num * t
    return num
 
n, t = map(int, input().split())
print(solve(n, t))