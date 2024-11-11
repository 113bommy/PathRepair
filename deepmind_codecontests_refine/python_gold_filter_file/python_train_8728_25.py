import itertools
import math

x,y = map(int,input().split())

if abs(x-y) >= 2:
    print("Alice")
else:
    print("Brown")