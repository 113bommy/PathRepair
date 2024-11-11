def Binary(s):
    L = 0; R = s
    while L <= R - 1:
        c = (L+R) // 2
        x = (1 + c)*c//2
        if s == x:
            return c
        elif x<s:
            L = c+1
        else: R = c
    return L - 1
        
a,b = map(int,input().split())
s = a + b
C = list(range(1,Binary(s)+1))
A = []; B = []
for i in range(len(C)-1,-1,-1):
    n = C[i]
    if a - C[i] >= 0:
        a -= C[i]
        A.append(C[i])
    else:
        B.append(C[i])
    
print(len(A))
print(*A)
print(len(B))
print(*B)
