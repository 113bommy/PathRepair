x = int(input())
ans = 1
for i in range(2, x+1):
    n = i*i
    while(n < x):
        ans = max(ans, n)
        n *= i
print(ans)