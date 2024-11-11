import math
n = int(input())
if n <= 2:
    ans = [1]
elif n == 3:
    ans = [1, 3]
elif n == 4:
    ans = [3, 1, 4, 2]
else:
    ans = [2*i + 1 for i in range(math.ceil(n / 2))] + [2*i + 2 for i in range(n//2)]
print(len(ans))
print(*ans)
