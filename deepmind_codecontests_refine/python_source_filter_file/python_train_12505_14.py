import math
import sys

n = int(input())
if n < 4:
    print(-1)
else:
    if n % 2 == 0:
        print(n - 2, end=" ")
    else:
        print(n - 1, end=" ")
    print(2)
