n = int(input())
G = list(map(int,input().split()))
D = {}
M = 0
for i in G:
    if i-1 in D:
        D[i] = D[i-1] + 1
    else:
        D[i] = 1
    if D[i]>M:
        M = D[i]
        Mi = i
#print(M,Mi)
R = []
A = Mi
for i in range(len(G)-1,-1,-1):
    if G[i] == A:
        R.append(i+1)
        A-=1
print(M)
print(*R[::-1])