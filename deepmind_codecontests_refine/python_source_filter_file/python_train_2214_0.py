res = ''
for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    c = [0]*(n+1)
    r = 0
    for i, row in enumerate(a):
        m = 0 
        for row2 in a[i+1:]:
            if row == row2: r += m
            m += c[row]
        c[row] += 1
    res += f'{r}\n'
print(res)