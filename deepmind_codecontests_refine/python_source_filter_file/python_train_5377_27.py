n = int(input())
ans = 1

for i in  range(1, n//2):
    if((n-i)%i == 0):
        ans += 1

print(ans)
