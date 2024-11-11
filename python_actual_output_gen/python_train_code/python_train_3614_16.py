n = int(input())
x = [sum([int(x) for x in input().split(" ")]) for _ in range(n)]
y= list(reversed(sorted(x)))
print(y)
print(y.index(x[0])+1)