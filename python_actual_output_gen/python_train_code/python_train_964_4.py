n = int(input())
a = [int(x) for x in input().split()]
print(max([min([a[i+1]-a[i] for i in range(n-2)])] + [a[i+1]-a[i] for i in range(n-1)]))
