def count_zeroes(x):
    i = 5
    c = 0
    while x//i:
        c += x//i
        i *= 5
    return c

def solve(n):
    x = n * 5
    if count_zeroes(x) == n:
        return x
    while count_zeroes(x) > n:
        x -= 5
    return x if count_zeroes(x) == n else 0

n = int(input())

p = solve(n)

if not p:
    print(p)
else:
    print(5)
    for i in range(p,p + 5):
        print(i,end = ' ')