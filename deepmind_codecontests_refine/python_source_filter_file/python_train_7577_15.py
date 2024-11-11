import math
N =int(input())
S = input()
# S = "".join(["BWWB" for i in range(25*10**3)])
N = len(S)//2
MOD = 10**9+7

L,R = 1,0
r = []
if S[0] != "B":
    print(0)
    exit()
r.append(L)

for i in range(1,len(S)):
    if S[i]!=S[i-1]:
        r.append(r[-1])
    else:
        r.append(1-r[-1])
if sum(r) != N or r[-1] != R:
    print(0)
    exit()

lc = 0
c = 1
for rr in r:
    if rr == R:
        c = (c*lc)%MOD
        lc -=1
    else:
        lc += 1
print(c*math.factorial(N) )

