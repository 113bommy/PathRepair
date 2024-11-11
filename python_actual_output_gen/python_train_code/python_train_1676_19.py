def readln(): return tuple(map(int, input().split()))

n, = readln()
print(pow(3, n - 1, 10**6 + 3) if n else 0)
