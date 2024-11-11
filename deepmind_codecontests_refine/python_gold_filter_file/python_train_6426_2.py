n,m = [int(x) for x in input().split()]

A = [int(x) for x in input().split()]
A = [sorted(x) for x in zip(A[::2],A[1::2])]
B = [int(x) for x in input().split()]
B = [sorted(x) for x in zip(B[::2],B[1::2])]

def isNeg(A,B):
    for x1,y1 in A:
        matched = [False,False]
        for x2,y2 in B:
            if x1==x2 and y1==y2:
                continue
            if x1 == x2 or x1 == y1:
                matched[0] = True
            if y1 == y2 or y1 == x2:
                matched[1] = True
        if all(matched):
            return True


pos_res = -2

def isPos():
    pos = set()
    for x1,y1 in A:
        for x2,y2 in B:
            if x1==x2 and y1==y2:
                continue
            if x1 == x2 or x1 == y2:
                pos.add(x1)
            if y1 == y2 or y1 == x2:
                pos.add(y1)
    global pos_res
    if(len(pos)) == 1:
        for x in pos:
            pos_res = x
    return len(pos) == 1

if isNeg(A,B) or isNeg(B,A):
    print(-1)
elif isPos():
    print(pos_res)
else:
    print(0)
    
            
