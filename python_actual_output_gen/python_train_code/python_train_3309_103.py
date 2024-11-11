[n, a, b] = [int(x) for x in input().split()]

print(min((n-a), (n+b)//2))

