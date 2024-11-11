N = int(input())
A = [int(a) for a in input().split()]

if max(A) <= 0:
    ma = - 10 ** 9
    for i, a in enumerate(A):
        if a > ma:
            ma = a
            mai = i
    print(ma)
    print(N - 1)
    for i in range(mai+1, N)[::-1]:
        print(i+1)
    for i in range(mai):
        print(1)
else:
    E = sum([a for a in A[::2] if a > 0])
    O = sum([a for a in A[1::2] if a > 0])
    ANS = []
    if O > E:
        ANS.append(1)
        A = A[1:]
    if len(A) % 2 == 0:
        ANS.append(len(A))
        A.pop()
    
    while len(A) > 1:
        if A[0] < 0:
            ANS.append(1)
            ANS.append(1)
            A = A[2:]
        elif A[-1] < 0:
            ANS.append(len(A))
            A.pop()
            ANS.append(len(A))
            A.pop()
        elif A[-3] < 0:
            ANS.append(len(A) - 2)
            A[-3] = A.pop()
            A.pop()
        else:
            ANS.append(len(A) - 1)
            A[-3] += A[-1]
            A.pop()
            A.pop()
    
    print(A[0])
    print(len(ANS))
    for a in ANS:
        print(a)