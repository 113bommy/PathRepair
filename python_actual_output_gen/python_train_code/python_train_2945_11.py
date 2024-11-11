tests = int(input())

def compute(hp, n, m):
    while n and hp and hp//2 + 10 < hp:
        n -= 1
        np = hp//2 + 10
    return "YES" if (hp <= m * 10) else "NO"

for x in range(tests):
    hp, n, m = map(int, input().split())
    print(compute(hp, n, m))