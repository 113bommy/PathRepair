n = int(input())
a = [int(i) for i in input().split()]
a.sort()

print(a[n//2])
