n, x = map(int, input().split())

output = []
c = [0] * x
m = 0

for _ in range(n):
    t = int(input())
    c[t % x] += 1

    while c[m % x] != 0:
        c[m % x] -= 1
        m += 1

    output.append(m)

print(*output, sep='\n')
