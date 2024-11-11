n = int(input())
a = [int(x) for x in input().split()]
a.sort(reverse=True)
print(sum(a[1:2*n][::2]))