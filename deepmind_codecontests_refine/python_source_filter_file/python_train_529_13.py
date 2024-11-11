n, l, a = map(int, input().split())
q, brk = 0, 0

for i in range(n):
    x, y = map(int, input().split())
    brk += (x - q) // a
    q = y
brk += (l - q) // a
print(brk)
