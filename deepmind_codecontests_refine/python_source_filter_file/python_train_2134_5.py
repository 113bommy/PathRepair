a1,b1 = map(int,input().split())
a2,b2 = map(int,input().split())
a3,b3 = map(int,input().split())
good = 0
if a2 + a3 <= a1:
    if b1 >= b2 and b1 >= b3: good = 1
if a2 + b3 <= a1:
    if b1 >= a3 and b1 >= b2: good = 1
if b2 + a3 <= a1:
    if b1 >= b3 and b1 >= a2: good = 1
if b2 + b3 <= a1:
    if b1 >= a2 and b1 >= a3: good = 1
    
if a2 + a3 <= b1:
    if a1 >= b2 and a1 >= b3: good = 1
if a2 + b3 <= b1:
    if a1 >= a3 and a1 >= b2: good = 1
if b2 + a3 <= b1:
    if a1 >= b3 and a1 >= a2: good = 1
if b2 + b3 <= b1:
    if a1 >= b2 and a1 >= b3: good = 1
    
print('YES' if good else 'NO')
