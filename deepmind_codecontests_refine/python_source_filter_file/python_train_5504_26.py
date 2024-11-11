import math

N = int(input())
for i in range(N):
    a = int(input())
    b = int(input())
    if a >= 10**79 or b >= 10 ** 79 or a + b >= 10 ** 79:
        print("overflow")
    else:
        print(a + b)