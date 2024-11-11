n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
print(sum(a[0:n-1]))
