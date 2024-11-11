a = [int(x) for x in input().split()]

dp = []
dp.append(a[0])
dp.append(a[1])
dp.append(a[1]-a[0])
dp.append(-a[0])
dp.append(-a[1])
dp.append(-a[1]-a[0])

n = int(input())

print(dp[(n-1)%6]%1000000007)
