n = int(input())
if n == 2:
    exit(print(0))
ans = n-1
for i in range(2,int(n**(0.5)+1)):
    if n % i == 0 and (n//i-1) >= i:
        ans += n//i-1
print(ans)