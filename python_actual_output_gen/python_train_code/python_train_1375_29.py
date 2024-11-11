N = int(input())
P = 0
L = []
C = input()
L.append(C)
for j in range(1,N):
    D = input()
    L.append(D)
    if L[j-1]!=L[j]: P+=1
print(P)
