int_inp   = lambda: int(input()) #integer input
strng     = lambda: input().strip() #string input
strl      = lambda: list(input().strip())#list of strings as input
mul       = lambda: map(int,input().split())#multiple integers as inpnut
mulf      = lambda: map(float,input().split())#multiple floats as ipnut
seq       = lambda: list(map(int,input().split()))#list of integers
import math
from collections import Counter,defaultdict


for _ in range(int_inp()):
    a,b = mul()
    m = seq()
    if sum(m)==b:
        print("Yes")
    else:
        print("N0")
