n = int(input())
a = [int(k) for k in input().split()]
b = [a[k]/max(k-1,n-k) for k in range(n)]
print(int(min(b)))