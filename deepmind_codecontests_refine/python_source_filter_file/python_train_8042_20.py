import sys
input = sys.stdin.readline
from collections import *

for _ in range(int(input())):
    n = int(input())
    
    if n%4==0:
        print('9'*(n-n//4)+'0'*(n//4))
    else:
        print('9'*(n-n//4-1)+'8'+'0'*(n//4))