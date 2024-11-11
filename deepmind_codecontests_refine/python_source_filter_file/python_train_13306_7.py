L = int(input())
L2 = bin(L)[2:]
N = len(L2)
L2d = L2[1:]
L2u = int("0b"+L2,0) - int("0b"+L2d,0)
L2u2 = L2u//2
tmp = 1
M = 0
Ans = []
if L2u != 0:
    tmpN = N
    while tmp != L2u:
        Ans.append([tmpN-1,tmpN,0])
        Ans.append([tmpN-1,tmpN,tmp])
        tmp *= 2
        tmpN -= 1
        M += 2
flag = 0
for i in range(len(L2d)):
    if L2d[i] == "1" and flag == 0:
        Ans.append([1, i+2, L2u])
        tmp = 2**(N-i-2)
        M += 1
        flag = 1
        B = L2u
    elif L2d[i] == "1":
        Ans.append([1, i+2, B+tmp])
        B = B+tmp
        tmp = tmp//2
        M += 1
print(*[N,M])
for i in range(M):
    print(*Ans[i])