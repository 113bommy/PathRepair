n = int(input())
a = [int(i) for i in input().split()]
a.sort()
print(sum(a[n:2*n]))