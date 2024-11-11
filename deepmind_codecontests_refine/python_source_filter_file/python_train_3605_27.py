import random
import re
import sys

n = int(input())
ar = list(map(int, input().split()))
br = list(map(int, input().split()))

sum = 0
sorted(br)
for i in range(0, n):
    sum = sum + ar[i]

if (br[n - 1] + br[n - 2] >= sum):
    print("YES")
else:
    print("NO")