n = int(input())
a = [int(_) for _ in input().split()]
a.sort()
print(sum(a[n:2*n]))
