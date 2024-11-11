# -*- coding: utf-8 -*-
# 写経した
import re
class Num:
    def __str__(self):
        return str(self.x)
    def __init__(self, value):
        self.x = value
    def __add__(self, value):
        return Num(self.x + value.x)
    def __sub__(self, value):
        return Num(self.x - value.x)
    def __mul__(self, value):
        return Num(self.x * value.x)
    def __truediv__(self, value):
        return Num(self.x // value.x)
      
N = int(input())
for i in range(N):
    s = input()[:-1]
    s = re.sub(r'(\d+)',r'Num(\1)',s)
    print(eval(s))
