#!/usr/bin/env python3
def ri():
    return map(int, input().split())

x1, y1 = ri()
x2, y2 = ri()
x3, y3 = ri()


print(x2-x1 + x3, y2-y1 + y3)
print(x3-x2 + x1, y3-y2 + y1)
print(x1-x3 + x2, y1-y3 + y2)
