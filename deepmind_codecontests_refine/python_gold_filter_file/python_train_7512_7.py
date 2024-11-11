n,k = list(map(int, input().split()))
a = list(map(int, input().split()))
a.sort()
b = [a[i+1]-a[i] for i in range(n-1)]
b.sort()
print(sum(b[:n-k]))