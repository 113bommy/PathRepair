n = int(input())
x = [int(_) for _ in input().split()]

x.sort()
print(sum(x[n:n*2]))
