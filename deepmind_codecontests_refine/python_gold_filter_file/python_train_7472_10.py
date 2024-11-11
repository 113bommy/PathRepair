n = int(input())
left = []
right = []
for i in range(n):
    s = input()
    n0 = 0
    n1 = 0
    l = len(s)
    for j in range(l):
        if s[j] == "(":
            n0 += 1
        else:
            if n0 == 0:
                n1 += 1
            else:
                n0 -= 1
    if n0 > 0 or n1 > 0:
        if n0 >= n1:
            left.append([n1, n0])
        else:
            right.append([n0, n1])
 
left.sort()
right.sort()
 
def solve():
    nl0 = 0
    nl1 = 0
    for p in left:
        if p[0] > nl0:
            return False
        nl0 -= p[0]
        nl0 += p[1]
    nr0 = 0
    nr1 = 0
    for p in right:
        if p[0] > nr1:
            return False
        nr1 -= p[0]
        nr1 += p[1]
    if nl0 == nr1:
        return True
    else:
        return False
 
if solve():
    print("Yes")
else:
    print("No")