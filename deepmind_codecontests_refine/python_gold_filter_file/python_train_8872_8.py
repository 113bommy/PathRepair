t = int(input())

def solve(n):
    if n == 1:
        return 1
    else:
        return n

for _ in range(t):
    n = int(input())
    print(solve(n))