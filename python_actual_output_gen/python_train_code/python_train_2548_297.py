n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
print(sum(a[n:2*n]))