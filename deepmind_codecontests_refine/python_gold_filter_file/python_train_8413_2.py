Q = int(input())
L = []
for i in range(Q):
    L.append([int(x) for x in input().split()])
    
for i in range(Q):
    a = min(L[i])
    b = max(L[i])
    if a == b:
        ans = 2*a-2
    elif a+1 == b:
        ans = 2*a-2
    else:
        c = int((a*b)**0.5)
        if c**2 == a*b:
            c -= 1
        if c*(c+1) >= a*b:
            ans = 2*c-2
        else:
            ans = 2*c-1
    print(ans)