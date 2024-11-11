def mex(L,R):
    if L == R:
        T = 0
    elif L*2<R:
        if R%2:
            T = R//2
        else:
            T = (R//2)-1
    else:
        if R%L==0:
            L+=1
        T = R%L
    return T
N = int(input())
Z = []
for q in range(N):
    l, r = list(map(int, input().split()))
    Z.append(mex(l,r))
for me in Z:
    print(me)