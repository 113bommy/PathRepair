for tc in range(int(input())):
    n = int(input())
    A = input().split(' ')
    for i in range(n):
        A[i] = int(A[i])
    notinindex = []
    move = []
    for i in range(n):
        if A[i] != i:
            notinindex.append(i)
    while notinindex != []:
        B = list(set(range(n+1)) - set(A))[0]
        if B == n:
            move.append(notinindex[0]+1)
            A[notinindex[0]] = n
        else:
            move.append(B+1)
            A[B] = B
            notinindex.remove(B)
    print(len(move))
    for i in move:
        print(i, end=' ')
    print()
        
        
    
