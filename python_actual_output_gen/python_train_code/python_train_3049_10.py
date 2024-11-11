t = int(input())

def solve(n):
    if n == 1:
        return 1
    else:
        return 2

for _ in range(t):
    n = int(input())
    print(solve(n))