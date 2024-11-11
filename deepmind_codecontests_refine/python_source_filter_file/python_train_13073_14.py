from collections import defaultdict

n = int(input())
s1 = input()
s2 = input()

occ = defaultdict(int)

for i in s2:
    occ[int(i)]+=1

def find_min(x):
    global occ
    for i in range(x, 10):
        if occ[i] > 0:
            occ[i]-=1
            return i
    for i in range(0, x):
        if occ[i] > 0:
            occ[i]-=1
            return i

mn = 0
for i in s1:
    y = find_min(int(i))
    if y < int(i):
        mn+=1

print(mn)

for i in s2:
    occ[int(i)]+=1

def find_closest(x):
    global occ
    for i in range(x+1, 10):
        if occ[i] > 0:
            occ[i] -=1
            return i
    for i in range(x, -1, -1):
        if occ[i] > 0:
            occ[i]-=1
            return i
mx =0
for i in s1:
    y = find_closest(int(i))
    if y > int(i):
        mx +=1

print(mx)
