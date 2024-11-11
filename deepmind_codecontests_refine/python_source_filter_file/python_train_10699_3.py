T=int(input()
for _ in range(T):      
    N = int(input())
    A = list(map(int, input().split()))
    S = list(map(int, input()))

    for i in range(N-1, -1, -1):
        ai = A[i]
        if ai==0:
            continue
        top = ai.bit_length() - 1

        #assert ai & 1<<top
        for j in range(i-1, -1, -1):
            if A[j] >> top & 1:
                A[j] ^= ai
    print(A,S)
    for a, c in zip(A[::-1], S[::-1]):
        if c==1 and a:
            break
    else:
        print("0")
        continue
    print("1")