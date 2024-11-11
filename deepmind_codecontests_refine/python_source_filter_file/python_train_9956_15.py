#author : Piyush Rajendra Chaudhari
import math

a, b, c = list(map(int, input().split()))
z = 0
r = a
for i in range(1, 200):
    x = (10 * r) // b
    r = (10 * r) % b
    if c == x:
        print(i)
        z += 1
        break

if z == 0:
    print(-1)
