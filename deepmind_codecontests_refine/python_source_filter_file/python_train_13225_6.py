n, m = [int(i) for i in input().split()]
a = [[int(j) for j in input().split()] for i in range(n)]
b = [int(input()) for i in range(m)]

ans = [sum([a[j][i] * b[i] for i in range(4)]) for j in range(3)]
print(*ans, sep='\n')
