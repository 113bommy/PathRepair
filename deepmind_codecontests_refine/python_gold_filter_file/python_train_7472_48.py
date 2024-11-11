def score(a,b):
    if b-a >= 0:
        return a
    else:
        return 10**6+1-b

N = int(input())

A = [0]*N
B = [0]*N

for i in range(N):
    S = input()
    a = 0
    b = 0
    for j in range(len(S)):
        if S[j] == ')':
            a += 1
        else:
            a -= 1
        A[i] = max(A[i],a)

        if S[-j-1] == '(':
            b += 1
        else:
            b -= 1
        B[i] = max(B[i],b)

#print('S',S)
#print('A',A)
#print('B',B)

L = sorted(list(range(N)),key = lambda i:score(A[i],B[i]))

SA = 0
SB = 0

#print('L',L)

for i in range(N):
    if SB > A[L[i]]:
        SB += B[L[i]] - A[L[i]]
    else:
        SA += A[L[i]]-SB
        SB = B[L[i]]
    #print(SA,SB)

if SA == 0 and SB == 0:
    print('Yes')
else:
    print('No')