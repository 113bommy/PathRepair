def checker(v, k, n):
    sum = 0
    i = 1
    lines = v
    while sum < n and lines > 0:
        sum += lines
        i += 1
        lines = int(v/(k**i))
    return sum > n
    
n, k = input().split(' ')
n = int(n)
k = int(k)

lb = int(n * (1 - (1/k)))

while not checker(lb, k, n):
    lb += 1
print(lb)