n = int(input())
a = [int(temp) for temp in input().split()]
a.sort()
print(a[int(len(a)/2)])