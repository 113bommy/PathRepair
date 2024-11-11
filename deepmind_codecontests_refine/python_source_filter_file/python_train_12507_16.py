n = int(input())
a = [int(input().split()[0]) for i in range(n)]
k = int(input())
print(n - sum(k > a[i] for i in range(1, len(a))))
