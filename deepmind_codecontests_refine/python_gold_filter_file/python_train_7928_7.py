import sys

n = int(sys.stdin.readline().strip())
s = sys.stdin.readline().strip()
m = int(sys.stdin.readline().strip())
L = [[0] * 26 for x in range (0, n)]
for i in range (0, n):
    if i != 0:
        L[i] = L[i-1][:]
    L[i][ord(s[i])-ord('a')] = L[i][ord(s[i])-ord('a')] + 1
for i in range (0, m):
    t = sys.stdin.readline().strip()
    A = [0] * 26
    for l in t:
        A[ord(l)-ord('a')] = A[ord(l)-ord('a')] + 1
    i1 = 0
    j1 = n
    while i1 + 1 != j1:
        k = (i1 + j1) // 2
        v = True
        for j in range (0, 26):
            if A[j] > L[k - 1][j]:
                v = False
        if v == True:
            j1 = k
        else:
            i1 = k
    print(j1)