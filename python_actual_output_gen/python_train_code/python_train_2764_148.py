n = int(input())
temp = [int(s) for s in input().split(' ')]
ans = 0
print(temp)
for i in range(n):
    ans += temp[i]
print(round(ans/n, 5))
