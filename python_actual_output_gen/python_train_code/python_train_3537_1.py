S=input()

A="abcdefghijklmnopqrstuvwxyz"
if S=="zyxwvutsrqponmlkjihgfedcba":
    print(-1)
elif len(S)!=26:
    A=list(A)
    for i in range(len(S)):
        A.remove(S[i])
    print(S+A[0])
else:
    a=A.index(S[25])
    for i in range(24,-1,-1):
        b=A.index(S[i])
        if a>b:
            break
        a=b

    for j in range(b+1,26):
        if not A[j] in S[:i]:
            print(S[:i]+A[b+1])
            break
