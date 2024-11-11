import sys
import math
input = sys.stdin.readline
 
n,m = list(map(int,input().split()))
a = input()

sub = a[:m]

if sub.count('9') == len(sub):
    print(len(a))
    print('9' * len(a))
else:
    p = (sub*math.ceil(n/m))[:len(a)]
    if int(p)>=int(a):
        print(len(a))
        print(p)
    else:
        sub = str(int(sub) + 1)
        p = (sub*math.ceil(n/m))[:len(a)]
        print(len(a))
        print(p)