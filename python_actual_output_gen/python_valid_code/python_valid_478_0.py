def solve():
    n = int(input())
    a = input()
    b = input()

    x, y, z = 0, 0, 0
    for i in range(n):
        if a[i] == '1':
            x += 1
        if b[i] == '1':
            y += 1
        if a[i] != b[i]:
            z += 1

    if x == y:
        if n-x+1 == y:
            return min(z, n-z)
        return x
    elif n-x+1 == y:
        return n-z
    return -1
    

for _ in range(int(input())):
    print(solve())