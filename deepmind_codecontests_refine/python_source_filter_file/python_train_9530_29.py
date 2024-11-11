def solve(n):
    for item in range(n):
        n,b,a = input().split()
        if int(b) >= 2400 and int(a) > 2400:
            return "YES"
    return "NO"

n = int(input())
print(solve(n))
