m, n = (int(x) for x in input().split(' '))

print(sum(i * (i/m)**n - ((i-1)/m)**n for i in range(1, m+1)))