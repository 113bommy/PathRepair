from math import log
a, b = map(int, input().split())
print(log(b/a)//log(1.5) + 1)