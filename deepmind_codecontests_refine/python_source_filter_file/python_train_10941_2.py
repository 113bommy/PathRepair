import sys
#import bisect
#import math
#import itertools
def get_line(): return list(map(str,sys.stdin.readline().strip().split()))
def in1(): return int(input())

d={}
for _ in range(in1()):
    x,s=get_line()
    x=int(x)
    if s=="BA" or s=="AB":
        s="AB"
    elif s=="BC" or s=="CB":
        s="BC"
    elif s=="AC" or s=="CA":
        s="AC"
    elif s=="ABC" or s=="BAC" or s=="BCA" or s=="CAB" or s=="CBA" or s=="ACB":
        s="ABC"
    if s not in d.keys():
        d[s]=x
    else:
        if d[s]>x:
            d[s]=x
b=[]
print(d)
if "ABC" in d.keys():
    b.append(d["ABC"])
if "A" in d.keys() and "BC" in d.keys():
        b.append(d["A"]+d["BC"])
if "B" in d.keys() and "AC" in d.keys():
        b.append(d["B"]+d["AC"])
if "C" in d.keys() and "AB" in d.keys():
    b.append(d["C"]+d["AB"])
if "AB" in d.keys() and "BC" in d.keys():
    b.append(d["AB"]+d["BC"])
if "BC" in d.keys() and "AC" in d.keys():
    b.append(d["BC"]+d["AC"])
if "AB" in d.keys() and "AC" in d.keys():
    b.append(d["AB"]+d["AC"])
if "A" in d.keys() and "B" in d.keys() and "C" in d.keys():
    b.append(d["A"]+d["B"]+d["C"])
if "A" in d.keys() and "B" in d.keys() and "AC" in d.keys():
    b.append(d["A"]+d["B"]+d["AC"])
if "A" in d.keys() and "B" in d.keys() and "BC" in d.keys():
    b.append(d["A"]+d["B"]+d["BC"])
if "A" in d.keys() and "C" in d.keys() and "BC" in d.keys():
    b.append(d["A"]+d["C"]+d["BC"])
if "A" in d.keys() and "C" in d.keys() and "AB" in d.keys():
    b.append(d["A"]+d["C"]+d["AB"])
if "B" in d.keys() and "C" in d.keys() and "AC" in d.keys():
    b.append(d["C"]+d["B"]+d["AC"])
if "C" in d.keys() and "B" in d.keys() and "AB" in d.keys():
    b.append(d["C"]+d["B"]+d["AB"])
if len(b)==0:
    print(-1)
else:
    print(min(b))

