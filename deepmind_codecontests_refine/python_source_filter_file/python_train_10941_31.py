import math

n=int(input())
minA=minB=minC=minAB=minAC=minBC=minABC=100005
a=[]
s=[]
for i in range(n):
    ai,si=input().split()
    ai=int(ai)
    a.append(ai)
    s.append(si)
    if si == "A":
        minA = min(ai,minA)
    elif si == "B":
        minB = min(ai,minB)
    elif si == "C":
        minC = min(ai,minC)
# print(a,s)
# print(minBC)
for i in range(n):
    if s[i] == "AB" or s[i] == "BA":
        minAB = min(a[i], minAB)
    elif s[i] == "AC" or s[i] == "CA":
        minAC = min(a[i],minAC)
    elif s[i] == "BC" or s[i] == "CB":
        minBC = min(a[i],minBC)

minAB = min(minAB, minA+minB)
minAC = min(minAC, minA+minC)
minBC = min(minBC, minB+minC)

for i in range(n):
    if s[i] == "ABC" or s[i] == "ACB" or s[i] == "BCA" or \
        s[i] == "BAC" or s[i] == "CAB" or s[i] == "CBA":
        minABC = min(a[i], minABC)
    
minABC=min(minABC, minAB+minC,minAC+minB,minBC+minA,minA+minB+minC,\
           minAB+minAC, minAB+minBC, minAC+minBC)

# print('A',minA)
# print('B',minB)
# print('C',minC)
# print('AB',minAB)
# print('AC',minAC)
# print('BC',minBC)
if minABC==100005:
    print("-1")
else:
    print(minABC)

