import math

N = int(input())
for i in range(N):
    a = int(input())
    b = int(input())
    if a >= 10 ** 80 or b >= 10 ** 80 or a + b >= 10 ** 80:
        print("overflow")
    else:
        print(a + b)