# Sourav Basak Shuvo KUET BME'18

t = int(input())

for i in range(t):
    ans = []
    n = int(input())
    for i in range(n):
        ans.append((i+1)*n)
    print(*ans)