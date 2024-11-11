import math

def solve(n, d):
    if (d <= n):
        return "YES"
    else:
        i = 1
        while (i < n):
            exp = (i + math.ceil(d / (i + 1)))
            if  exp <= n:
                return "YES"
            i = i+1
        return "NO"


t = int(input())

for _ in range(t):
    n, d = map(int, input().split(' '))
    print(solve(n,d))
