a, b, c = [int(i) for i in input().split()]
print(len([i for i in range(a, b+1) if c % i == 0]))

