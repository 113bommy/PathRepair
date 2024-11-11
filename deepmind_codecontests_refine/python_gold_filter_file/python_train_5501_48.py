n, m, k = map(int, input().split())
r = "No"
for i in range(n+1):
    for j in range(m+1):
        if i*m+j*n-2*i*j == k:
            r = "Yes"
print(r)