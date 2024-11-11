n = int(input())
a = [int(i) for i in input().split()]
a.sort(reverse=True)
print(sum(a[n:2*n]))