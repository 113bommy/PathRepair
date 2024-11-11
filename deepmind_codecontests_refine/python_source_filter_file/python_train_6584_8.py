import math

for _ in range(int(input())):
        n, k = map(int, input().split())
        if k >= n:
                print(1)
        else:
                j = 1
                ans = n
                while j * j  <= n:
                        if n % j == 0:
                                if j < k:
                                        ans = min(ans, n// j)
                                if n // j < k:
                                        ans = min(ans, j)
                        j += 1
                print(ans)
