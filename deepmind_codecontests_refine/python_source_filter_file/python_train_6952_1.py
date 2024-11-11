import sys
input = sys.stdin.readline

A = input().rstrip()
B = input().rstrip()
C = input().rstrip()

def check(P1, P2, P3):
    L1 = len(P1)
    L2 = len(P2)
    L3 = len(P3)
    L = max([L1, L2, L3])*2+3

    P12 = [True]*L
    for i2 in range(-L2, L1+1):
        for l in range(max(i2, 0), min(i2+L2, L1)):
            if P1[l] != "?" and P2[l-i2] != "?" and P1[l] != P2[l-i2]:
                P12[i2] = False
                break
    
    P13 = [True]*L
    for i3 in range(-L3, L1+1):
        for l in range(max(i3, 0), min(i3+L3, L1)):
            if P1[l] != "?" and P3[l-i3] != "?" and P1[l] != P3[l-i3]:
                P13[i3] = False
                break
    
    P23 = [True]*L
    for i3 in range(-L3, L2+1):
        for l in range(max(i3, 0), min(i3+L3, L2)):
            if P2[l] != "?" and P3[l-i3] != "?" and P2[l] != P3[l-i3]:
                P23[i3] = False
                break

    ans = L1 + L2 + L3
    for i2 in range(-L2, L1+1):
        for i3 in range(-L3, L1+1):
            if P12[i2] and P13[i3] and P23[i3-i2]:
                ans = min(ans, max([L1, L2+i2, L3+i3]) - min([0, i2, i3]))
    return ans



print(min([check(A, B, C), check(B, A, C), check(C, A, B)]))