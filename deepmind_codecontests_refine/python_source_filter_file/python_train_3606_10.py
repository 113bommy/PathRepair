import math
n = int(input())
x = list(map(int, input().split()))
ans = 0
for i in range(n):
    if x[i] < 0:
        ans = x[i]
    else:
        if math.sqrt(x[i]) != round(math.sqrt(x[i])):
            ans = x[i]
print(ans)
