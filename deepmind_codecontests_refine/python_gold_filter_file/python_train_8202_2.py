n = int(input())
ans = 0
i = 1
x = n
while i<n**0.5:
    if (n-i)%i==0:
        x = (n-i)//i
        if x<=i:break
        ans += x
    i += 1
print(ans)