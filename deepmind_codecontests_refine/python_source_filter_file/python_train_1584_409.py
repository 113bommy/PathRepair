import os
import sys

from io import BytesIO

# input = BytesIO(os.read(0, os.fstat(0).st_size)).readline


def isPrime(x):
    if x < 3:
        return True
    for i in range(3, (int(x ** 0.5)) + 1):
        if x % i == 0:
            return False
    return True
a = int(input())
if isPrime(a + 8):
    print(a + 9, 9)
else:
    print(a + 8, 8)
