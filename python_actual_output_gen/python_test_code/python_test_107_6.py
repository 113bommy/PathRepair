def ans():
    N=int(input())
    A=input()
    Ans=0
    for j in range(len(A)-2):
        for i in range(j+3):
            if A[i]!='x':
                break
        else:
            Ans+=1
    print(Ans)
ans()
