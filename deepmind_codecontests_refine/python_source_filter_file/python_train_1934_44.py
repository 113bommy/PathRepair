#5
import math

n = int(input())
ans = []
if (n % 2 == 0):
    print(int(n / 2))
    while (n > 0):
        ans.append(2)
        n -= 2
elif (n % 2 == 1):
    print(int((n - 3) / 2))
    n -= 3
    ans.append(3)
    while (n > 0):
        ans.append(2)
        n -= 2

print(" ".join(map(str, ans)))
