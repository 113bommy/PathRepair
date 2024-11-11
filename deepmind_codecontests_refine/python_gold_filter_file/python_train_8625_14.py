#coding: utf-8
import math

s = input()
ans = math.floor(len(s)/2) - s.count("p")
print(ans)