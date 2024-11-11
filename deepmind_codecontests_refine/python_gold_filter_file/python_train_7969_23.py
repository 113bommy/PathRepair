a = int(input())
def solve(a):
    if a <= 2: return None
    if a % 2:
        x, y = a//2, a//2 + 1
        return (2*x*y, x*x + y*y)
    else:
        x, y = a//2, 1
        return (x*x - y*y, x*x + y*y)

A = solve(a)
if A is None:
    print(-1)
else:
    print(A[0], A[1])



