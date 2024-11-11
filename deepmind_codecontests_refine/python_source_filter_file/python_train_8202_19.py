n = int(input())

ans = 0
for i in range(1,n):
    if (n-i)/i > i:
        if (n-i)%i == 0:
            ans += (n-i)/i
    else:
        break
print(int(ans)