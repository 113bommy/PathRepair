A=input()
b=list()
def rev(A): return A[::-1]
C = rev(A)
for e in range(0, len(A)):
    b.append(A[e])
if A == C:
    print(A)
else:
    for i in range(1, len(C)):
        b.append(C[i])
    strb = ''.join(str(x) for x in b)
    print(strb)