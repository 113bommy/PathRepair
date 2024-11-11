# python rough_work.py < in > out && cat out && diff -qs out check
# n = int(input())
import math
n, k = [int(var) for var in input().split()]
# n, k = 9, 4

maxOnes = 0
powers, power = [1], int(math.log2(n))

for i in range(power+1):
    if n & 1 << i: maxOnes += 1 

for i in range(power):
    powers.append(powers[-1]*2)

# print(powers)
if not(maxOnes <= k <= n):
    print('NO')
else:
    print("YES")
    while k != 0:
        if k==n :
            for _ in range(k):
                print(1, end = " ")
            
            k, n = 0, 0
        else:
            for Idx in reversed(range(1+int(math.log2(n)))):
                if k - 1 <= n - powers[Idx]:
                    k -= 1
                    n -= powers[Idx]
                    print(powers[Idx], end = " ")
                    break
    print()

