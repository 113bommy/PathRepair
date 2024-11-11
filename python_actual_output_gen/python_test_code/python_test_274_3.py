n, k = list(map(int, input().strip().split()))
a = list(map(int, input().strip().split()))

sup = 0

for i in range(1, n+1):
    sup += (min(k, i, n-i+1)) * a[i-1]
sup /= (n-k+1.0)
print(sup)