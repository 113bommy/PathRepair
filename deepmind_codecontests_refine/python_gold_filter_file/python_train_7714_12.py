# C[n+1] = sum(C[i]*C[n-i]) 0 <= i <= n
# C[0] = 1
a, b = [int(p) for p in input().split()]
print('YES')
for i in range(a, b, 2):
    print(i, i+1)