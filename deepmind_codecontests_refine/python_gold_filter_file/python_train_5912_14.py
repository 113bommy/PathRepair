N,K,C = map(int,input().split())
S = input()
L = []
R = []
i = 0
while i < N:
    if S[i] == "o":
        L.append(i)
        if len(L) == K:
            break
        i += C+1
    else:
        i += 1
i = N-1
while i >= 0:
    if S[i] == "o":
        R.append(i)
        if len(R) == K:
            break
        i -= C+1
    else:
        i -= 1
R.reverse()
for i in range(K):
    if L[i] == R[i]:
        print(L[i]+1)
