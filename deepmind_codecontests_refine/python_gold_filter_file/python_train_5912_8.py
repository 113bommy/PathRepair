# E - Yutori
N,K,C = map(int,input().split())
S = input()
L = [0]*K
R = [0]*K

i = 0
for j in range(K):
    while S[i]!='o':
        i += 1
    L[j] = i
    i += C+1

i = N-1
for j in range(K-1,-1,-1):
    while S[i]!='o':
        i -= 1
    R[j] = i
    i -= C+1
    
for j in range(K):
    if L[j]==R[j]:
        print(L[j]+1)