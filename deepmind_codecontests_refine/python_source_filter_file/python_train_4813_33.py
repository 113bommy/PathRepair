import bisect

def find_le(x, a):
    'Find rightmost value less than or equal to x'
    i = bisect.bisect_right(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_ge(x, a):
    'Find leftmost item greater than or equal to x'
    i = bisect.bisect_left(a, x)
    if i != len(a):
        return a[i]
    return a[0]

def getA(a,b):
    le = find_le(a,Divs[b])
    ge = find_ge(a,Divs[b])

    if abs(le-a) < abs(ge-a):
        return le
    else:
        return ge

def getC(c,b):
    k = c//b

    c1 = (k-1)*b
    c2 = k*b
    c3 = (k+1)*b

    d1 = abs(c1 - c)
    d2 = abs(c2 - c)
    d3 = abs(c3 - c)

    if min([d1,d2,d3]) == d1 and c1 >= b:
        return c1
    elif min([d1,d2,d3]) == d2 and c2 >= b:
        return c2
    else:
        return c3

T = int(input())

Divs = []
for i in range(20001):
    tmp = i
    divs = []

    for j in range(1,int(tmp**0.5)+1):
        if tmp % j == 0:
            divs.append(j)
    
    for j in range(len(divs)):
        divs.append(i // divs[j])

    Divs.append(sorted(list(set(divs))))


for t in range(T):
    a,b,c = [int(k) for k in input().split()]
    best = pow(10,10)
    ABC = [0,0,0]
    
    for B in range(1,10001):
        A = getA(a,B)
        C = getC(c,B)

        if abs(A - a) + abs(B - b) + abs(C - c) < best:
            best = abs(A - a) + abs(B - b) + abs(C - c)
            ABC = [A,B,C]

    print(best)
    print(ABC[0],ABC[1],ABC[2])
        

    
