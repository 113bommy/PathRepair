from collections import *
for _ in range(int(input())):
    n = int(input())
    A = list(input())
    B = list(input())
    swap = []
    ans = True
    C = Counter(A+B)
    for c in C:
        ans = ans and not(C[c] % 2)
    if not ans:
        print("No")
        continue
    for i in range(n):
        if A[i] == B[i]:
            continue
        for j in range(i + 1,n):
            if A[i] == A[j]:
                swap.append((i+1,j+1))
                B[i],A[j] = A[j],B[i]
                break
            if A[i] == B[j]:
                swap.append((j+1,j+1))
                swap.append((j+1,i+1))
                B[i],B[j],A[j] = B[j],A[j],B[i]
                break
    print("Yes")
    print(len(swap))
    for i in swap:
        print(str(i[0]) + " " + str(i[1]))

