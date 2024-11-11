from sys import stdin, stdout

n = int(stdin.readline())

a = sorted([int(x) for x in stdin.readline().split()], reverse=True)

if n <= 3:
    base = 0
    for x in a:
        base = base | x
    print(base)

else:
    high = 0

    for x in range(n):
        for y in range(x,n):
            for z in range(y,n):
                high = max(high, x | y | z)

    print(high)

    
