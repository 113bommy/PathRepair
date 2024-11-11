import sys 
import math
from collections import Counter,defaultdict
LI=lambda:list(map(int,input().split()))
MAP=lambda:map(int,input().split())
IN=lambda:int(input())
S=lambda:input()

def case():
    a,b,c = sorted(MAP())
    print(a+b+c)
for _ in range(IN()):
    case()
